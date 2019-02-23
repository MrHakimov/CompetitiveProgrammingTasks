// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1;
vector<long long> t;
vector<int> a;

void build(int v, int tl, int tr){
	if(tl==tr) t[v] = a[tl];
	else{
		int tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		t[v] = t[2*v]+t[2*v+1];
	}
}

long long sum(int v, int tl, int tr, int l, int r){
	if(l>r) return 0;
	if(tl==l && tr==r) return t[v];
	int tm = (tl+tr)/2;
	long long ans=sum(2*v, tl, tm, l, min(tm,r))+sum(2*v+1, tm+1, tr, max(l,tm+1), r);
	return ans;
}

void update(int v, int tl, int tr, int pos, int new_val){
	if(tl==tr) t[v] = new_val;
	else{
		int tm = (tl+tr)/2;
		if(pos<=tm) update(v*2, tl, tm, pos, new_val);
		else update(v*2+1, tm+1, tr, pos, new_val);
		t[v] = t[2*v]+t[2*v+1];
	}
}

void solve() {
	int n,k,i,l,r;
	char q;
	cin >> n >> k;
	a.clear();
	a.assign(n,0);
	t.resize(n*4);
	build(1,0,n-1);
	for(i=0;i<k;i++){
		cin >> q >> l >> r;
		l--;
		if(q=='A') update(1,0,n-1,l,r);
		else{
			long long ct = sum(1,0,n-1,l,r-1);
			cout << ct << endl;
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
	fin("sum.in"); fout("sum.out");
	while (TN--) solve();
	return 0;
}