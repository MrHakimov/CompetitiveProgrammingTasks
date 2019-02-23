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
const int N = 2e5 + 1;
int a[N];
pair < int, int > pipe[N];
vector < LL > sum(N, 0ll), ans(N, 0ll);
int p[N], rk[N];

int get(int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
}

bool join(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) {
        return 0;
    }
    
    if (rk[a] > rk[b]) {
        swap(a, b);
    }
    p[a] = b;
    rk[b] += rk[a];
    return 1;
}

vector < bool > used(N, 0);
vector < vector < int > > g(N, vector < int > ());
int h[N];

void dfs(int u, int p) {
    sum[u] = a[u];
    for (auto v : g[u]) {
        if (v != p) {
            h[v] = h[u] + 1;
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
}

void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = i;
        rk[i] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        pipe[i] = {u, v};
        if (join(u, v)) {
            g[u].pb(v);
            g[v].pb(u);
            used[i] = 1;
        }
    }
    
    LL total = 0ll;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    if (total != 0ll) {
        cout << "Impossible\n";
        return;
    }
    
    h[0] = 0;
    dfs(0, -1);
    
    cout << "Possible\n";
    for (int i = 0; i < m; i++) {
        if (used[i]) {
            int u = pipe[i].fi, v = pipe[i].se;
            if (h[u] < h[v]) {
                ans[i] = sum[v];
            } else {
                ans[i] = -sum[u];
            }
        }
        cout << ans[i] << endl;
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