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
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] % 2 + 1e5;
    }
    cout << n + 1 << endl;
    cout << "2 " << n << " 2" << endl;
    cout << "1 " << n << " 100000" << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << "2 " << i + 1 << " " << a[i] - i << endl;
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