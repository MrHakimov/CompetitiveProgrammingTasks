/// author: Mr.Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define LD long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1;
vector < vector < int > > g;
vector < int > mod2;
vector < int > used;
int vertexes = 0, count2 = 0;
const LL MOD = 998244353;

LL binpow(LL x, LL y, LL N = 998244353)
{
  if (y == 0) return 1;
  LL z = binpow(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return (x*z*z) % N;
}

bool count(int u, int val = 1) {
    bool result = true;
    mod2[u] = val;
    if (val == 2ll) {
        count2++;
    }
    vertexes++;
    for (auto v: g[u]) {
        if (!mod2[v]) {
            int newVal = 3 - val;
            result &= count(v, newVal);
        } else if (val == mod2[v]) {
            return false;
        }
    }
    return result;
}

void solve() {
    g.clear();
    mod2.clear();
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    mod2.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    LL ans = 1LL;
    for (int i = 1; i <= n; i++) {
        if (!mod2[i]) {
            count2 = 0;
            vertexes = 0;
            if (!count(i)) {
                cout << 0 << endl;
                return;
            }
            ans *= binpow(2, count2) + binpow(2, vertexes - count2);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	/// fin("file.in"); fout("file.out");
	cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}