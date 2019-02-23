/// Author: mr.omti - Muhammadjon Hakimov

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
    int n, k;
    cin >> n >> k;
    int g;
    cin >> g;
    for(int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g = __gcd(g, x);
    }
    set < int > ans;
    LL s = 0;
    for(int i = 0; i < k; i++) {
        ans.insert(s % k);
        s += g;
    }
    cout << (int)ans.size() << endl;
    for(auto el: ans) cout << el << " ";
    cout << endl;
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