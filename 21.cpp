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
const int N = 1e5 + 1;
vector < vector < int > > g(N, vector < int > ());
vector < LL > s(N), a(N, 0);

void dfs(int u, int prev = -1, int h = 1) {
    if (h % 2 == 0) {
        if ((int)g[u].size() == 0) {
            s[u] = s[prev];
        } else {
            LL ai = s[g[u][0]];
            for (auto v: g[u]) {
                ai = min(ai, s[v]);
            }
            ai -= s[prev];
            if (ai < 0) {
                cout << -1;
                exit(0);
            }
            a[u] = ai;
            s[u] = s[prev] + ai;
            for (auto v: g[u]) {
                a[v] = s[v] - s[u];
            }
        }
    }
    for (auto v: g[u]) {
        dfs(v, u, h + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    a[1] = s[1];
    dfs(1);
    LL ans = 0ll;
    for (int i = 1; i <= n; i++) {
        ans += a[i];
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