// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1;

void solve() {
	long long n;
	int k;
	cin >> n >> k;
	multiset<int> a;
	long long n_copy = n;
	int cnt = 0;
	while(n_copy){
		if(n_copy % 2 == 1){
			a.insert(cnt);
		}
		cnt++;
		n_copy /= 2;
	}
	if(a.size() == k){
		cout << "Yes" << endl;
		for(auto i = a.rbegin(); i != a.rend(); i++) cout << *i << " ";
	}
	else if(a.size() < k){
		int ln = a.size();
		while(a.size() < k){
			int itrtr = *a.rbegin();
			a.erase(a.find(itrtr));
			a.insert(itrtr - 1);
			a.insert(itrtr - 1);
		}
		int max_ = *a.rbegin();
		a.clear();
		n_copy = n;
		cnt = 0;
		while(n_copy){
			if(n_copy % 2 == 1){
				a.insert(cnt);
			}
			cnt++;
			n_copy /= 2;
		}
		while(a.size() < k){
			int itrtr = *a.rbegin();
			if(itrtr <= max_) itrtr = *a.begin();
			a.erase(a.find(itrtr));
			a.insert(itrtr - 1);
			a.insert(itrtr - 1);
		}
		cout << "Yes" << endl;
		for(auto i = a.rbegin(); i != a.rend(); i++) cout << *i << " ";
	}
	else cout << "No";
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