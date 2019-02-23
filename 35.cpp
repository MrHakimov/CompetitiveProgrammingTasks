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
    LL n, k, M, d;
    cin >> n >> k >> M >> d;
    LL ans = 0;
    for (LL i = 1; i <= d; i++) {
        LL l = 1, r = M + 1;
        while (r - l > 1) {
            LL m = (l + r) / 2;
            if ((n / m + k - 1) / k >= i) {
                l = m;
            } else {
                r = m;
            }
        }
        LL ii = (n / l + k - 1) / k;
        if (ii > i) {
            continue;
        }
        ans = max(ans, l * ii);
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