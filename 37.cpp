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
const int N = 2e5 + 1;

void solve() {
    int n;
    cin >> n;
    vector < pair < pair < int, int >, int > > vp;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vp.pb({{l, r}, i});
    }
    sort(all(vp));
    int col[n];
    col[vp[0].se] = 1;
    int l = vp[0].fi.fi, r = vp[0].fi.se;
    bool f = 0;
    for (int i = 1; i < n; i++) {
        col[vp[i].se] = 1;
        if (f) {
            col[vp[i].se] = 2;
            continue;
        }
        if (vp[i].fi.fi > r) {
            f = 1;
            col[vp[i].se] = 2;
        } else {
            r = max(vp[i].fi.se, r);
        }
    }
    if (f) {
        for (int i = 0; i < n; i++) {
            cout << col[i] << " ";
        }
    } else {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("file.in"); fout("file.out");
    cin >> TN;
    /// =========================================
    while (TN--) solve();
    return 0;
}