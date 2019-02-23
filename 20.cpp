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

void solve() {
	string s;
	cin >> s;
	int n = (int)s.length();
	vector < bool > ans(n, 0);
	for (int i = 1; i < n; i++) {
	    if (s[i] == 'a') {
	        ans[i - 1] = ans[i - 1] == 1 ? 0 : 1;
	        ans[i] = 1;
	    }
	}
	for (int i = 0; i < n; i++) {
	    cout << ans[i] << " ";
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