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
const LL INF = 1e18;

int n, m, k;
vector < int > res;

pair < int, int > p[N];
LL dist[N];
bool vis[N];
vector < pair < int, int > > t[N];
vector < pair < pair < int, int >, int> > g[N];

void dijkstra(int s) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}
	dist[s] = 0;
	
	priority_queue < pair < LL, LL > > q;
	q.push({0, s});
	
	while (!q.empty()) {
		int u = q.top().se;
		q.pop();
		
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		
		if (p[u].fi > 0) {
			t[p[u].fi].pb({u, p[u].se});
		}
		
		for (auto v : g[u]) {
			if (dist[v.fi.fi] > dist[u] + v.fi.se) {
				dist[v.fi.fi] = dist[u] + v.fi.se;
				p[v.fi.fi] = {u, v.se};
				q.push({-dist[v.fi.fi], v.fi.fi});
			}
		}
	}
}

void dfs(int u) {
	for (auto v : t[u]) {
		if ((int)res.size() < k) {
			res.pb(v.se);
		}
		dfs(v.fi);
	}
}

void solve() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].pb({{v, c}, i});
		g[v].pb({{u, c}, i});
	}
	
	dijkstra(1);
	dfs(1);
	
	cout << (int)res.size() << endl;
	for(int v: res) {
		cout << v << " ";
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