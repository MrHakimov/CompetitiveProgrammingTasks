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

int TN = 1;
vector<vector<int> > g;
vector<int> pust, d, dp, used;
queue<int> q;

LL ans = 1;

void bfs(){
	q.push(1);
	d[1] = 1;
	dp[1] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++){
			int to = g[v][i];
			if(!used[to]){
				d[to] = d[v] + 1;
				q.push(to);
				dp[d[to]]++;
				used[to] = 1;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++){
		g.pb(pust);
		d.pb(-1);
		dp.pb(0);
		used.pb(0);
	}
	int x;
	for(int i = 0; i < n - 1; i++){
		cin >> x;
		g[x].pb(i + 2);
	}
	bfs();
	for(int i = 2; i <= n; i++){
		if(dp[i] != 0) ans += dp[i] % 2;
	}
	cout << ans;
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