/// author: Muhammadjon Hakimov

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
int n, m;
int a[20][20];
LL d[20][(1 << 20)];

void calc (int x = 0, int y = 0, int mask = 0, int nextMask = 0) {
	if (x == n) {
		return;
	}
	if (y >= m) {
		d[x + 1][nextMask] += d[x][mask];
	}
	else {
		int my_mask = (1 << y);
		if (a[x][y] == 1) {
			calc (x, y + 1, mask, nextMask);
		}
		else {
			if (mask & my_mask) {
				calc(x, y + 1, mask, nextMask);
			} else {
				if (a[x][y] == 0 && a[x + 1][y] == 0) {
					calc (x, y + 1, mask, nextMask | my_mask);
				}
				if (y  +1 < m && a[x][y] == 0 && a[x][y + 1] == 0 && ! (mask & (my_mask << 1))) {
					calc (x, y + 2, mask, nextMask);
				}
			}
		}
	}
}


void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
	    string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] != '.') {
				a[i][j] = 1;
			} else {
			    a[i][j] = 0;
			}
		}
	}
	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			calc(i, 0, j, 0);
		}
	}
	cout << d[n][0];
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	fin("domino-covering-2.in"); fout("domino-covering-2.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}