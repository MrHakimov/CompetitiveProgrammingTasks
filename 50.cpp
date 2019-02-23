/// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1;
const int N = 1e5 + 1;

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int A[n + 1];
    for(int i = 1; i <= n; i++) cin >> A[i];
    vector < vector < int > > g, ans;
    vector < int > pustoy;
    for(int i = 0; i <= n; i++) g.pb(pustoy), ans.pb(pustoy);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int i = 1; i <= k; i++) {
        queue < int > q;
        int dist[n + 1];
        for(int j = 0; j <= n; j++) dist[j] = -1;
        for(int j = 1; j <= n; j++) {
            if(A[j] == i) {
                q.push(j);
                dist[j] = 0;
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(auto to: g[v]) {
                if(dist[to] == -1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        for(int j = 1; j <= n; j++) {
            ans[j].pb(dist[j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        sort(ans[i].begin(), ans[i].end());
        LL cur_dist = 0;
        for(int j = 0; j < s; j++) {
            cur_dist += ans[i][j] * 1ll;
        }
        cout << cur_dist << " ";
    }
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	/// fin("file.in"); fout("file.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}