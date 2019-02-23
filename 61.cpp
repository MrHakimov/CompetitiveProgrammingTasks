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
const int INF = 1000000, N = 2005;
vector<vector<pair<int, int> > > g(N);
vector<int> d(N, INF), p(N);
priority_queue<pair<int, int> > q;

void dijkstra(){
    while(!q.empty()){
        int v = q.top().se, cur_d = -q.top().fi;
        q.pop();
        if(cur_d > d[v]) continue;
        for(int j = 0; j < g[v].size(); j++){
            int to = g[v][j].fi, len = g[v][j].se;
            if(d[to] > d[v] + len){
                d[to] = d[v] + len;
                p[to] = v;
                q.push(mp(-d[to], to));
            }
        }
    }
}

void solve() {
    int n, s, f, x;
    cin >> n >> s >> f;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x != -1) g[i].pb(mp(j, x));
        }
    d[s] = 0;
    q.push(mp(0, s));
    dijkstra();
    if(d[f] == INF) cout << -1;
    else cout << d[f];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// =========================================
	// fin("input.txt"); fout("output.txt");
	fin("dijkstra.in"); fout("dijkstra.out");
	// cin >> TN;
	// =========================================
	while (TN--) solve();
	return 0;
}