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

map < LL, string > mp;

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        if(x == 4) {
            cout << "YES\n";
            continue;
        }
        if(x == 1) {
            cout << "NO\n";
            continue;
        }
        if(mp.count(x)) {
            cout << mp[x];
            continue;
        }
        LL sq = sqrt(x);
        if(sq * sq != x) {
            mp[x] = "NO\n";
            cout << "NO\n";
            continue;
        }
        bool f = 1;
        for(LL j = 2; j * j * j * j <= x; j++) {
            if(sq % j == 0) {
                mp[x] = "NO\n";
                cout << "NO\n";
                f = 0;
                break;
            }
        }
        if(f) cout << "YES\n", mp[x] = "YES\n";
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