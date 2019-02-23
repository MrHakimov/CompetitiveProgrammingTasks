// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define LL long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1, d[300002];
vector<vector<pair<int, int> > > g;
vector<int> used, ans;
vector<pair<int, int> > pust;

bool dfs(int v){
    if(used[v]) return 1;
    used[v] = 1;
    int dg = 0;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i].fi, edge = g[v][i].se;
        if(dfs(to) == 0){
            dg++;
            ans.pb(edge);
        }
    }
    return (d[v] == -1 || dg % 2 == d[v]);
}

void solve() {
    int n, m, root = -1;
    cin >> n >> m;
    for(int i = 0; i < n + 2; i++){
        g.pb(pust);
        used.pb(0);
    }
    for(int i = 1; i <= n; i++){
        cin >> d[i];
        if(d[i] == -1) root = i;
    }
    if(root == -1) root = 1;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb({y, i});
        g[y].pb({x, i});
    }
    if(!dfs(root)){
        cout << -1;
        return;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
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