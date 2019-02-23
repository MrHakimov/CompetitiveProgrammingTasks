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
    int n, m;
    cin >> n >> m;
    LL a[n], c[n];
    set < pair < pair < LL, int >, LL > > st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            st.insert({{c[i], i}, a[i]});
        }
    }
    for (int i = 0; i < m; i++) {
        LL t, d;
        cin >> t >> d;
        t--;
        LL ans = 0ll;
        if (a[t] > d) {
            st.erase({{c[t], t}, a[t]});
            st.insert({{c[t], t}, a[t] - d});
            a[t] -= d;
            ans += d * c[t];
        } else {
            d -= a[t];
            ans += a[t] * c[t];
            if (a[t] != 0) {
                st.erase({{c[t], t}, a[t]});
                a[t] = 0;
            }
            while (d != 0 && (int)st.size() > 0) {
                if ((*st.begin()).se <= d) {
                    d -= (*st.begin()).se;
                    ans += (*st.begin()).se * (*st.begin()).fi.fi;
                    a[(*st.begin()).fi.se] = 0;
                    st.erase(st.begin());
                } else {
                    LL p1 = (*st.begin()).fi.fi, p2 = (*st.begin()).se, id = (*st.begin()).fi.se;
                    st.erase(st.begin());
                    st.insert({{p1, id}, p2 - d});
                    a[id] = p2 - d;
                    ans += p1 * d;
                    d = 0;
                }
            }
        }
        if ((int)st.size() == 0 && d != 0) {
            cout << 0 << endl;
        } else {
            cout << ans << endl;
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