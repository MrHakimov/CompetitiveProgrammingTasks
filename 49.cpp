/// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1, n, a[4][55];
vector < pair < int, int > > vpii;

bool check() {
    vpii.clear();
    for(int i = 0; i < n; i++) {
        if(a[1][i] > 0 && a[0][i] == a[1][i]) vpii.pb({1, i});
    }
    for(int i = 0; i < n; i++) {
        if(a[2][i] > 0 && a[3][i] == a[2][i]) vpii.pb({2, i});
    }
    if((int)vpii.size() == 0) return 0;
    return 1;
}

void solve() {
    int k;
    cin >> n >> k;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    if(k == 2 * n) {
        if(!check()) {
            cout << -1;
            return;
        }
    }
    vector < int > ans;
    for(int i = 0; i < 2 * n; i++) {
        check();
        int x, y;
        bool f = 0;
        for(int j = 0; j < (int)vpii.size(); j++) {
            ans.pb(a[vpii[j].fi][vpii[j].se]);
            if(vpii[j].fi == 1) ans.pb(vpii[j].fi - 1);
            else ans.pb(vpii[j].fi + 1);
            ans.pb(vpii[j].se);
            a[vpii[j].fi][vpii[j].se] = 0;
        }
        int b[4][55], stx = -1, sty = -1;
        bool f_st = 0;
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < n; k++) {
                b[j][k] = a[j][k];
            }
        }
        for(int j = 1; j < 3; j++) {
            for(int k = 0; k < n; k++) {
                if(!f_st && a[j][k] > 0) {
                    if(j == 1) {
                        if(k == 0 && a[2][k] == 0) {
                            stx = j;
                            sty = k;
                            f_st = 1;
                        }
                        else if(k - 1 >= 0 && a[1][k - 1] == 0) {
                            stx = j;
                            sty = k;
                            f_st = 1;
                        }
                    }
                    else {
                        if(k == n - 1 && a[1][n - 1] == 0) {
                            stx = j;
                            sty = k;
                            f_st = 1;
                        }
                        else if(k + 1 < n && a[2][k + 1] == 0) {
                            stx = j;
                            sty = k;
                            f_st = 1;
                        }
                    }
                }
            }
        }
        if(stx != -1 && sty != -1) {
            for(int j = 0; j < 2 * n; j++) {
                if(a[stx][sty] > 0) ans.pb(a[stx][sty]);
                if(stx == 1) {
                    if(sty - 1 >= 0) {
                        if(a[stx][sty] > 0) ans.pb(stx);
                        if(a[stx][sty] > 0) ans.pb(sty - 1);
                        if(sty == n - 1) stx++;
                        else sty++;
                    }
                    else {
                        if(a[stx][sty] > 0) ans.pb(stx + 1);
                        if(a[stx][sty] > 0) ans.pb(sty);
                        sty++;
                    }
                }
                else {
                    if(sty + 1 < n) {
                        if(a[stx][sty] > 0) ans.pb(stx);
                        if(a[stx][sty] > 0) ans.pb(sty + 1);
                        if(sty == 0) stx--;
                        else sty--;
                    }
                    else {
                        if(a[stx][sty] > 0) ans.pb(stx - 1);
                        if(a[stx][sty] > 0) ans.pb(sty);
                        sty--;
                    }
                }
            }
        }
        b[1][n - 1] = a[2][n - 1];
        b[2][0] = a[1][0];
        for(int j = 0; j < n - 1; j++) {
            b[1][j] = a[1][j + 1];
        }
        for(int j = 1; j < n; j++) {
            b[2][j] = a[2][j - 1];
        }
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < n; k++) a[j][k] = b[j][k];
        }
    }
    cout << (int)ans.size() / 3 << endl;
    for(int i = 0; i < (int)ans.size(); i += 3) {
        cout << ans[i] << " " << ans[i + 1] + 1 << " " << ans[i + 2] + 1 << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	/// fin("file.in"); fout("file.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}