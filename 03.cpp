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

/* Just some advices:
1. If I use set/multiset, I will check it - is it correct to use set/multiset in a problem?
2. If I can't solve problem, I must write a program, which could help me to understand it much more better)
...
*/

using namespace std;

typedef long long LL;
typedef long double LD;

int TN = 1;

void solve() {
    string s;
    cin >> s;
    char c;
    int x = 0;
    while (s == "start") {
        cout << "? " << (1 << x) << " " << (1 << (x + 1)) << endl;
        cin >> c;
        if (c == 'e') {
            return;
        }
        if (c == 'x') {
            int l = (1 << x) - 1, r = (1 << (x + 1));
            while (r - l > 1) {
                int m = (l + r) / 2;
                cout << "? " << (1 << x) - 1 << " " << m << endl;
                cin >> c;
                if (c == 'x') {
                    r = m;
                } else {
                    l = m;
                }
            }
            cout << "! " << r << endl;
            cin >> s;
            if (s == "mistake" || s == "end") {
                return;
            }
            x = 0;
            continue;
        }
        x++;
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