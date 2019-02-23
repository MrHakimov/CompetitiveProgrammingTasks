/// author: Mr.Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

typedef long long LL;
typedef long double LD;

int TN = 1;

void solve() {
    int n, m;
    cin >> n >> m;
    LL p[m + 1][n + 1], next[m + 1][n + 1];
	for (int i = 0; i < m; i++) {
	    LL prev = 0;
		for (int j = 0; j < n; j++) {
			cin >> p[i][j];
			next[i][prev] = p[i][j];
			prev = p[i][j];
		}
		next[i][prev] = 0;
	}
	LL ans = 0ll;
	for (LL pos = 0; pos < n; ) {
	    LL len = 1;
	    bool f = 1;
		while (f && pos + len < n) {
			LL curr = p[0][pos + len];
			LL prev = p[0][pos + len - 1];
			for (int j = 1; j < m; j++) {
			    if (next[j][prev] != curr) {
			        f = 0;
			        break;
			    }
			}
			if (f) {
			    len++;
			}
		}
		ans += len * (len + 1) / 2;
		pos += len;
	}
	cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("file.in"); fout("file.out");
    /// cin >> TN;
    /// =========================================
    while (TN--) solve();
    return 0;
}