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
    vector < char > vec, ansVec;
    vec.pb('B');
    vec.pb('G');
    vec.pb('R');
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    do {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != vec[i % 3]) {
                cnt++;
            }
        }
        if (cnt < ans) {
            ans = cnt;
            ansVec = vec;
        }
    } while (next_permutation(all(vec)));
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << ansVec[i % 3];
    }
    cout << endl;
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