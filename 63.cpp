// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define LL long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1;

bool isPrime(int x){
	if(x % 2 == 0 && x != 2) return false;
	if(x == 2) return true;
	for(int i = 3; i * i <= x; i++) if(x % i == 0) return false;
	return true;
}

void solve() {
	LL n, m, sp;
	cin >> n >> m;
	sp = n;
	while(!isPrime(sp)) sp++;
	LL diff = sp - n + 2;
	cout << sp << " " << sp << endl;
	cout << 1 << " " << 2 << " " << diff << endl;
	int i;
	for(i = 2; i < n; i++) cout << i << " " << i + 1 << " " << 1 << endl;
	int p1 = 1, p2 = 3;
	for(i = n; i <= m; i++){
		cout << p1 << " " << p2 << " " << sp + 1 << endl;
		p2++;
		if(p2 > n){
			p1++;
			p2 = p1 + 2;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// =========================================
	// fin("input.txt"); fout("output.txt");
	// fin("bootfall.in"); fout("bootfall.out");
	// cin >> TN;
	// =========================================
	while (TN--) solve();
	return 0;
}