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
	int n;
	cin >> n;
	LL s[n], c[n];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	LL ans = 1e9;
	for(int j = 1; j < n - 1; j++) {
		LL cur = c[j], mn_i = 1e9, mn_k = 1e9;
		for(int i = 0; i < j; i++) {
			if(s[i] < s[j]) mn_i = min(mn_i, c[i]);
		}
		cur += mn_i;
		for(int k = j + 1; k < n; k++) {
			if(s[j] < s[k]) mn_k = min(mn_k, c[k]);
		}
		cur += mn_k;
		ans = min(ans, cur);
	}
	if(ans == 1e9) cout << -1;
	else cout << ans;
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