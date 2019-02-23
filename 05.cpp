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

/* Just some advices:
1. If I use set/multiset, I will check it - is it correct to use set/multiset in a problem?
2. If I can't solve problem, I must write a program, which could help me to understand it much more better)
...
*/

using namespace std;

typedef long long LL;
typedef long double LD;

int TN = 1;
const int N = 1e5 + 1;
int n;
vector < bool > used(N, 0);
vector < vector < int > > g(N, vector < int > ());
set < int > st;
vector < int > ans;

void dfs(int u) {
    used[u] = 1;
    for (auto i : g[u]) {
        if (!used[i]) {
            st.insert(i);
        }
    }
	if ((int)st.size() == 0) {
		return;
	}
	int v = *st.begin();
	ans.pb(v);
	st.erase(st.begin());
	dfs(v);
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
		g[b].pb(a);
    }
	ans.pb(1);
    dfs(1);
    for (auto i: ans) {
		cout << i << " ";
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
