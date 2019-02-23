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
    int n;
    cin >> n;
    vector < LL > b(n / 2, 0), a(n, 0);
    for (int i = 0; i < n / 2; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n / 2; i++) {
        a[i] = 0;
        a[n - 1 - i] = b[i];
        if (i > 0) {
            LL l = a[i - 1], r = a[n - 1 - i + 1];
            while (l < r) {
                LL m = (l + r) / 2;
                if (m >= a[i - 1] && b[i] - m <= a[n - 1 - i + 1]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            a[i] = r;
            a[n - 1 - i] = b[i] - r;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
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