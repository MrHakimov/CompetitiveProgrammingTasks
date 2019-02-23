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

void solve() {
    int a, n, m;
    cin >> a >> n >> m;
    map < int, bool > rain;
    map < int, LL > ans, weight;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for(int j = l + 1; j <= r; j++) rain[j] = 1;
    }
    for(int i = 1; i <= a; i++) ans[i] = weight[i] = 1e18;
    for(int i = 0; i < m; i++) {
        int x;
        LL p;
        cin >> x >> p;
        weight[x + 1] = min(p, weight[x + 1]);
    }
    for(int i = 1; i <= a; i++) {
        if(rain[i] == 0) {
            ans[i] = ans[i - 1];
            continue;
        }
        for(int j = 1; j <= i; j++) {
            if(weight[j] != 1e18) {
                ans[i] = min(ans[i], ans[j - 1] + (i - j + 1) * weight[j]);
            }
        }
    }
    if(ans[a] == 1e18) cout << -1;
    else cout << ans[a];
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