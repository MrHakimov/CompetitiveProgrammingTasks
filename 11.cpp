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
int n, m;

struct edge{
    int a, b, cost;
};

vector < edge > edges(N);
vector < vector < int > > g(N, vector < int > ());
vector < int > topSortList, ans;
bool used[N];
int topSortNum[N];

void dfs(int u) {
    used[u] = 1;
    for (auto v: g[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
    topSortList.pb(u);
}

bool can(int x) {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        used[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        if (edges[i].cost > x) {
            g[edges[i].a].pb(edges[i].b);
        }
    }
    
    topSortList.clear();
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(all(topSortList));
    
    for (int i = 0; i < (int)topSortList.size(); i++) {
        topSortNum[topSortList[i]] = i;
    }
    
    ans.clear();
    for (int i = 0; i < m; i++) {
        int u = edges[i].a, v = edges[i].b, curCost = edges[i].cost;
        if (curCost > x && topSortNum[u] > topSortNum[v]) {
            return false;
        } else if (curCost <= x) {
            if (topSortNum[u] > topSortNum[v]) {
                ans.pb(i + 1);
            }
            
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
    }
    
    int l = -1, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (can(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    can(r);
    cout << r << " " << (int)ans.size() << endl;
    for (auto el: ans) {
        cout << el << " ";
    }
    cout << endl;
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