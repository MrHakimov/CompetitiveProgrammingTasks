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
	int n, m;
	cin >> n >> m;
	if(m < n - 1) {
	    cout << "Impossible\n";
	    return;
	}
	vector < pair < int, int > > v;
	for(int i = 1; i <= n && m > 0; i++) {
		for(int j = i + 1; j <= n && m > 0; j++) {
			if(__gcd(i, j) == 1) {
				v.pb({i, j});
				m--;
			}
		}
	}
	if(m == 0) {
		cout << "Possible\n";
		for(auto p: v) cout << p.fi << " " << p.se << endl;
		return;
	}
	cout << "Impossible\n";
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