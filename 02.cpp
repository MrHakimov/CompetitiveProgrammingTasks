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
    LL k;
    cin >> k;
    LL ans = 1e18;
    if (k == 0) {
        cout << 0;
        return;
    }
    for (LL i = 1; i * i <= abs(k); i++) {
        LL u = i;
        if (k < 0) {
            u = -i;
        }
        LL v = k / u;
        if (u * v == k && (u + v) % 2 == 0) {
            ans = min(ans, (u + v) / 2);
        }
    }
    if (ans != 1e18) {
        cout << ans;
    } else {
        cout << "none";
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