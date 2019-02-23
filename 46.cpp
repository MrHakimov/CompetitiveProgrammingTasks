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
map < int, int > cnt;
map < string, bool > used;
set < char > base;
LL ans = 0;

vector < LL > fact;

void count() {
    int sz = 0;
    for(int i = 0; i <= 9; i++) sz += cnt[i];
    LL cur = fact[sz];
    for(auto el: base) {
        cur /= fact[cnt[(int)(el - '0')]];
    }
    if(cnt[0] > 0) {
        LL cur2 = fact[sz - 1];
        for(auto el: base) {
            if(el == '0') {
                cur2 /= fact[cnt[(int)(el - '0')] - 1];
            }
            else cur2 /= fact[cnt[(int)(el - '0')]];
        }
        cur -= cur2;
    }
    ans += cur;
}

void solve() {
    fact.resize(20);
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i <= 19; i++) fact[i] = fact[i - 1] * i;
	string n;
	cin >> n;
	sort(n.begin(), n.end());
	for(auto el: n) base.insert(el);
	for(int i = (1 << (int)base.size()) - 1; i < (1 << (int)n.size()); i++) {
	    string cur = "";
		cnt.clear();
		int id = 0, i1 = i;
		while(i1) {
			if(i1 % 2 == 1) cnt[(int)(n[id] - '0')]++, cur += n[id];
			i1 /= 2;
			id++;
		}
		if((int)cur.size() < (int)base.size()) continue;
		set < char > cur_st;
		for(auto el: cur) cur_st.insert(el);
		if(base != cur_st) continue;
		if(used[cur]) continue;
		used[cur] = 1;
		count();
	}
	cout << ans;
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