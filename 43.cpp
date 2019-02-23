#include <bits/stdc++.h>

#define LL long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
using namespace std;

int TN = 1;

void solve() {
    LL n, m, k;
	cin >> n >> m >> k;
	if(n * m * 2 / k * k != n * m * 2) {
		cout << "NO";
		return;
	}
	LL num = n * m * 2 / k;
	LL t1 = n, t2 = m * 2 / k;
	if(t1 * t2 != num) {
	    bool f = 1;
    	for(int i = 2; i <= n; i++) {
    	    if(num % i == 0 && num / i <= m) {
    	        f = 0;
    	        t1 = i;
    	        t2 = num / i;
    	        break;
    	    }
    	}
    	if(f) {
    	    t1 = 1;
    	    t2 = 1;
    	}
	}
	cout << "YES\n";
	cout << 0 << " " << 0 << endl;
	cout << t1 << " " << 0 << endl;
	cout << 0 << " " << t2 << endl;
}

int main() {
    //cin >> TN;
    while(TN--) solve();
}