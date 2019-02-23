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

int check(int mask, int index)
{
    return (mask & (1 << index)) != 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
	}
    int mask = (1 << n);
    vector <vector < LL > > d(mask, vector < LL > (m));
    for (int i = 0; i < mask; i++) {
        d[i][0] = 1;
	}
    for (int i = 1; i < m; i++) {
        for (int prev = 0; prev < mask; prev++) {
            for (int cur = 0; cur < mask; cur++) {
                bool f = 1;
                for (int j = 0; j < n - 1; j++) {
                    int summ = check(prev, j) + check(prev, j + 1) + check(cur, j) + check(cur, j + 1);
                    if (summ == 0 || summ == 4) {
                        f = 0;
                        break;
                    }
                }
                if (f) {
                    d[cur][i] += d[prev][i - 1];
				}
            }
		}
	}
    LL ans = 0ll;
    for (int i = 0; i < mask; i++) {
        ans += d[i][m - 1];
	}
    cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	fin("nice.in"); fout("nice.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}