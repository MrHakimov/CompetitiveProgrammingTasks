// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define all(x) (x.begin(), x.end())
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n,t,i,TN = 1;
pair<pair<int, int>, int> p[200002];
vector<int> res;

bool can(int x){
	res.clear();
	if(x==0) return true;
	i=0;
	int id=0,t_cur=0;
	while(id<n && i<x){
		if(p[id].fi.se >= x){
			i++;
			t_cur += p[id].fi.fi;
			res.pb(p[id].se);
			if(t_cur>t) return false;
		}
		id++;
	}
	if(res.size()==x) return true;
	return false;
}

void solve() {
	cin >> n >> t;
	for(i=0;i<n;i++){
		cin >> p[i].fi.se >> p[i].fi.fi;
		p[i].se = i+1;
	}
	sort(p+0,p+n);
	int l=0,r=n;
	while(l<r){
		int m=(l+r)/2;
		if(can(m+1)) l=m+1;
		else r=m;
	}
	can(l);
	cout << l << endl << l << endl;
	for(i=0;i<res.size();i++) cout << res[i] << " ";
	cout << endl;
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