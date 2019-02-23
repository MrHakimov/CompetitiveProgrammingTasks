// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1, n, x;
vector<ULL> arr;
ULL a, b;
string s, a_s, b_s;

ULL parse(string st){
	st = st + ".";
	ULL ans = 0, deg = 1;
	for(int i = 0; i < x - 1; i++) deg *= 256ULL;
	string cur = "";
	for(int i = 0; i < st.size(); i++){
		if(st[i] == '.'){
			ans += stoi(cur) * deg;
			deg /= 256ULL;
			cur = "";
		}
		else cur += st[i];
	}
	return ans;
}

void solve() {
	cin >> n >> x;
	for(int i = 0; i < n; i++){
	    cin >> s;
	    ULL ans = parse(s);
	    arr.pb(ans);
	}
	cin >> a_s >> b_s;
	a = parse(a_s); b = parse(b_s);
	int cnt = 0;
	vector<ULL> d;
	for(int i = 0; i < n; i++)
	    if(arr[i] >= a && arr[i] <= b){
	        cnt++;
	        d.pb(arr[i]);
	    }
	sort(all(d));
	bool answrd = false;
	for(int i = 1; i < d.size(); i++){
	    if(d[i] - d[i - 1] - 1 >= 2){
	        answrd = true;
	        break;
	    }
	}
	if(d.size() > 0 && (d[0] - a >= 2 || b - d[d.size() - 1] >= 2)) answrd = true;
	else if(d.size() == 0 && b - a + 1 >= 2) answrd = true;
	if(!answrd) cout << -1;
	else cout << b - a - cnt - 1;
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