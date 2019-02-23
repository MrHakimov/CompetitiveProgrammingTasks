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
    LL n, l, r;
    cin >> n >> l >> r;
    LL cnt[3];
    for (int i = 0; i < 3; i++) {
        cnt[i] = (r - l + 3) / 3;
    }
    if ((r - l + 1) % 3 != 0) {
        for (int i = 1; i <= 3 - (r - l + 1) % 3; i++) {
            cnt[(r + i) % 3]--;
        }
    }
    LL MOD = 1000000007ll;
    LL dp[n + 1][3];
    for (int i = 0; i < 3; i++) {
        dp[1][i] = cnt[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0ll;
            if (j == 0) {
                dp[i][j] += (dp[i - 1][0] * cnt[0]) % MOD;
                dp[i][j] += (dp[i - 1][1] * cnt[2]) % MOD;
                dp[i][j] += (dp[i - 1][2] * cnt[1]) % MOD;
            } else if (j == 1) {
                dp[i][j] += (dp[i - 1][0] * cnt[1]) % MOD;
                dp[i][j] += (dp[i - 1][1] * cnt[0]) % MOD;
                dp[i][j] += (dp[i - 1][2] * cnt[2]) % MOD;
            } else {
                dp[i][j] += (dp[i - 1][0] * cnt[2]) % MOD;
                dp[i][j] += (dp[i - 1][1] * cnt[1]) % MOD;
                dp[i][j] += (dp[i - 1][2] * cnt[0]) % MOD;
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][0];
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