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
const int N = 3e5 + 1;

void solve() {
    int n, m;
    cin >> n >> m;
    pair < LL, int > p[N];
    LL x[N], y[N], sumX = 0ll, sumY = 0ll;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        p[i] = {x[i] - y[i], i};
        sumY += y[i];
    }
    sort(p + 1, p + n + 1);
    LL ans[N];
    for (int i = 1; i <= n; i++) {
        int pos = p[i].se;
        sumY -= y[pos];
        ans[pos] += (n - i) * 1ll * x[pos] + sumY;
        ans[pos] += (i - 1) * 1ll * y[pos] + sumX;
        sumX += x[pos];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        LL mn = min(x[u] + y[v], x[v] + y[u]);
        ans[u] -= mn;
        ans[v] -= mn;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "\n" : " ");
    }
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