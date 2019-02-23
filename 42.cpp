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
    int n;
    cin >> n;
    set < LL > st;
    map < LL, LL > bal;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == ')' && s[(int)s.length() - 1] == '(') {
            continue;
        }
        LL balance = 0;
        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == '(') {
                balance++;
            } else {
                balance--;
            }
        }
        if (balance > 0) {
            bool bl = 0;
            LL bal1 = 0ll;
            for (int j = 0; j < (int)s.length() + balance; j++) {
                if ((j >= (int)s.length() && bal1 == 0) || (s[j] == ')' && bal1 == 0)) {
                    bl = 1;
                    break;
                }
                if (j >= (int)s.length() || s[j] == ')') {
                    bal1--;
                } else {
                    bal1++;
                }
            }
            if (bl) {
                continue;
            }
        } else {
            bool bl = 0;
            LL bal1 = 0ll;
            for (int j = 0; j < (int)s.length() + abs(balance); j++) {
                if (j >= abs(balance) && s[j - abs(balance)] == ')' && bal1 == 0) {
                    bl = 1;
                    break;
                }
                if (j < abs(balance) || s[j - abs(balance)] == '(') {
                    bal1++;
                } else {
                    bal1--;
                }
            }
            if (bl) {
                continue;
            }
        }
        if (balance > 0) {
            st.insert(balance);
        }
        if (!bal[balance]) {
            bal[balance] = 1ll;
        } else {
            bal[balance]++;
        }
    }
    LL ans = 0ll;
    for (auto el: st) {
        if (el == 0) {
            continue;
        }
        LL p = 0ll;
        if (bal[-el]) {
            p = bal[-el];
        }
        ans += min(bal[el], p);
    }
    if (bal[0]) {
        ans += bal[0] / 2ll;
    }
    cout << ans;
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