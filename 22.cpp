/// Author: Mr.Hakimov

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
const LL MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        cout << n << endl;
        return;
    }
    LL x1 = n, y1 = 1;
    LL x2 = n, y2 = n - 2;
    LL ans = 0ll;
    ans += (x1 * y1) % MOD;
    ans += (2 * x2 * y2) % MOD;
    LL lst = n;
    for (LL i = 1; i <= n - 3; i++) {
        ans += (lst * (((n - i) * (n - i - 2) * (i + 2)) % MOD)) % MOD;
        lst = (lst * (n - i)) % MOD;
    }
    cout << ans % MOD;
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