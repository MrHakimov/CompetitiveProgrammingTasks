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
    int n, q;
    cin >> n >> q;
    vector<LL> a, k;
    a.resize(n + 1); a[0] = 0;
    k.resize(q + 1); k[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= q; i++) cin >> k[i];
    vector<LL> sum;
    sum.resize(n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    int jivoy = 1;
    LL cur = 0;
    for(int i = 1; i <= q; i++) {
        int l = jivoy, r = n;
        while(l < r) {
            int m = (l + r) / 2;
            if(sum[m] - sum[jivoy - 1] - cur >= k[i]) r = m;
            else l = m + 1;
        }
        if(k[i] < sum[l] - sum[jivoy - 1] - cur) {
            cur = sum[l] - sum[jivoy - 1] - k[i] - cur;
			cur = a[l] - cur;
            jivoy = l;
        }
		else {
			l++;
			jivoy = l;
			cur = 0;
		}
		if(l > n) {
            jivoy = 1;
            cur = 0;
        }
        cout << n - jivoy + 1 << endl;
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