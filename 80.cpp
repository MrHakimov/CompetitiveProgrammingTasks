/// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define LD long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    vector < vector < int > > a(n + 1), d(n + 1);
    for (int j = 0; j <= m; j++) {
        a[0].pb(-11);
        d[0].pb(0);
    }
    for (int i = 1; i <= n; i++) {
        a[i].pb(-11);
        d[i].pb(0);
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i].pb(x);
            d[i].pb(0);
        }
    }
    d[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            d[i][j] = (int)(-1e7 - 1);
            if (i - 1 > 0 && d[i - 1][j] + a[i][j] > d[i][j]) {
                d[i][j] = d[i - 1][j] + a[i][j];
            }
            if (j - 1 > 0 && d[i][j - 1] + a[i][j] > d[i][j]) {
                d[i][j] = d[i][j - 1] + a[i][j];
            }
        }
    }
    cout << d[n][m] << endl;
    int i = n, j = m;
    vector < char > ans;
    while (!(i <= 1 && j <= 1)) {
        if (i - 1 > 0 && j - 1 <= 0) {
            i--;
            ans.pb('D');
            continue;
        }
        if (j - 1 > 0 && i - 1 <= 0) {
            j--;
            ans.pb('R');
            continue;
        }
        if (i - 1 > 0 && j - 1 > 0 && d[i - 1][j] > d[i][j - 1]) {
            i--;
            ans.pb('D');
        } else if (i - 1 > 0 && j - 1 > 0 && d[i][j - 1] >= d[i - 1][j]) {
            j--;
            ans.pb('R');
        }
    }
    reverse(all(ans));
    for (auto pr: ans) {
        cout << pr;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	fin("input.txt"); fout("output.txt");
	/// fin("file.in"); fout("file.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}