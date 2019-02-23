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
    int n, k;
    cin >> n >> k;
    LL a[n];
    vector < multiset < LL > > vst(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vst[1].insert(a[0]);
    int id = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            vst[id].insert(a[i]);
        } else {
            id++;
            vst[id].insert(a[i]);
        }
    }
    LL ans = 0ll;
    for (int i = 1; i <= id; i++) {
        auto it = vst[i].end();
        it--;
        //cout << (int)vst[i].size() << " " << k << endl;
        for (int j = 0; j < min(k, (int)vst[i].size()); j++) {
            //cout << *it << endl;
            ans += (*it) * 1ll;
            it--;
        }
    }
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