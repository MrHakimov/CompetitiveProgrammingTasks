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
int n, k;
LL A, B;
map < pair < int, int >, LL > counted;
vector < int > a;

LL f(int l, int r) {
    int cnt = (upper_bound(a.begin(), a.end(), r) - a.begin()) - (lower_bound(a.begin(), a.end(), l) - a.begin());
    if (counted[{l, r}]) {
        return counted[{l, r}];
    }
    if (l == r) {
        if (!cnt) {
            counted[{l, r}] = A;
            return A;
        }
        counted[{l, r}] = B * (cnt * 1ll);
        return counted[{l, r}];
    }
    LL cn = cnt * 1ll, a2 = B * cn * ((r - l + 1) * 1ll);
    if (cn == 0) {
        return A;
    }
    LL a1 = f(l, (r + l) / 2) + f((r + l) / 2 + 1, r);
    counted[{l, r}] = min(a1, a2);
    return counted[{l, r}];
}

void solve() {
    cin >> n >> k >> A >> B;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(all(a));
    cout << f(1, (1 << n));
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