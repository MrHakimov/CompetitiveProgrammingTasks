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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector < string > vec;
    vec.pb("");
    vec[0] += s[0];
    int id = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            vec.pb("");
            id++;
            vec[id] += s[i];
        } else {
            vec[id] += s[i];
        }
    }
    set < char > alph;
    alph.insert('B');
    alph.insert('G');
    alph.insert('R');
    id = 0;
    string ans = "";
    int res = 0;
    for (auto cur: vec) {
        for (int i = 0; i < (int)cur.length(); i++) {
            if (i % 2 == 0) {
                ans += cur[i];
            } else {
                set < char > curAlph = alph;
                curAlph.erase(cur[i]);
                if (id != (int)vec.size() - 1) {
                    curAlph.erase(vec[id + 1][0]);
                }
                ans += *curAlph.begin();
            }
        }
        id++;
        res += (int)cur.size() / 2;
    }
    cout << res << endl;
    cout << ans << endl;
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