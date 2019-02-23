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
string mn_mn;

int count(char ch1, char ch2) {
    string mn = mn_mn;
	int cnt = 0, ind = 0;
	for(int i = (int)mn.length() - 1; i >= 0; i--) {
		if(mn[i] == ch1) {
			ind = i;
			break;
		}
		cnt++;
	}
	if(cnt == (int)mn.length()) cnt = 0;
	for(int i = 0; i < cnt; i++) {
		swap(mn[ind], mn[ind + 1]);
		ind++;
	}
	int cnt_cur = 0;
	ind = 0;
	for(int i = (int)mn.length() - 2; i >= 0; i--) {
		if(mn[i] == ch2) {
			ind = i;
			break;
		}
		cnt_cur++;
		cnt++;
	}
	for(int i = 0; i < cnt_cur; i++) {
		swap(mn[ind], mn[ind + 1]);
		ind++;
	}
	if(mn[0] == '0') {
	    int cur_id = 0;
	    for(int i = 0; i < (int)mn.length(); i++) {
	        if(mn[i] != '0')  {
	            cur_id = i;
	            break;
	        }
	    }
	    if(cur_id == (int)mn.length() - 2 || cur_id == (int)mn.length() - 1) return 100;
	    cnt += cur_id;
	}
	if(((mn[(int)mn.length() - 2] - '0') * 10 + (mn[(int)mn.length() - 1] - '0')) % 25 == 0) return cnt;
	return 100;
}

void solve() {
	cin >> mn_mn;
	int ans = min(min(count('0', '0'), count('5', '2')), min(count('0', '5'), count('5', '7')));
	if(ans == 100) {
		cout << -1;
		return;
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