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

bool can(int m, int s) {
    if(s >= 0 && s <= m * 9) return 1;
    return 0;
}

void solve() {
    int m, s;
    cin >> m >> s;
    int s1 = s;
    string mn = "", mx = "";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 10; j++) {
            if((j == 0 && ((i == 0 && m == 1) || i > 0)) && can(m - i - 1, s)) {
                mn += '0';
                break;
            }
            if(j == 0) continue;
            if(can(m - i - 1, s - j)) {
                mn += char(j + 48);
                s -= j;
                break;
            }
        }
    }
    s = s1;
    for(int i = 0; i < m; i++) {
        for(int j = 9; j >= 0; j--) {
            if((j == 0 && ((i == 0 && m == 1) || i > 0)) && can(m - i - 1, s)) {
                mx += '0';
                break;
            }
            if(j == 0) continue;
            if(can(m - i - 1, s - j)) {
                mx += char(j + 48);
                s -= j;
                break;
            }
        }
    }
    if((int)mn.size() < m || (int)mx.size() < m) cout << "-1 -1\n";
    else cout << mn << " " << mx << endl;
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