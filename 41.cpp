/// author: Mr.Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

typedef long long LL;
typedef long double LD;

int TN = 1;

void solve() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int vopr = 0, zvez = 0, ostl = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '?') {
            vopr++;
        } else if (s[i] == '*') {
            zvez++;
        } else {
            ostl++;
        }
    }
    if (ostl == k) {
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] != '?' && s[i] != '*') {
                cout << s[i];
            }
        }
    } else if (k < ostl) {
        string ans = "";
        int cnt = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            char c = s[i];
            if ((c != '*' && c != '?') && (i < (int)s.length() - 1 && (s[i + 1] == '?' || s[i + 1] == '*')) && cnt < ostl - k) {
                cnt++;
                continue;
            } else {
                if (c != '*' && c != '?') {
                    ans += c;
                }
            }
        }
        if ((int)ans.length() == k) {
            cout << ans;
        } else {
            cout << "Impossible";
        }
    } else {
        string ans = "";
        bool f = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            if (!f && s[i] == '*') {
                for (int j = 0; j < k - ostl; j++) {
                    ans += s[i - 1];
                }
                f = 1;
            }
            if (s[i] != '*' && s[i] != '?') {
                ans += s[i];
            }
        }
        if ((int)ans.length() == k) {
            cout << ans;
        } else {
            cout << "Impossible";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("file.in"); fout("file.out");
    /// cin >> TN;
    /// =========================================
    while (TN--) solve();
    return 0;
}