// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1, N=510, cnt;
vector<vector<int> > g;
vector<int> pustoy, used;

void dfs(int u){
	used[u] = 1;
	for(size_t i=0; i<g[u].size(); i++){
		int v=g[u][i];
		if(used[v]==0) dfs(v);
		else if(used[v]==1) cnt++;
	}
	used[u] = 2;
}

void solve() {
	int n,m,i,j;
	for(i=0;i<N;i++){ g.pb(pustoy); used.pb(0); }
	cin >> n >> m;
	for(i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			used[j] = 0;
		}
		cnt = 0;
		dfs(i);
		for(j=1;j<=n;j++) if(used[j]==0) dfs(j);
		if(cnt<2){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// =========================================
	// fin("input.txt"); fout("output.txt");
	// fin("bootfall.in"); fout("bootfall.out");
	// cin >> TN;
	// =========================================
	while (TN--) solve();
	return 0;
}