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

int TN = 1;

void solve() {
    int n;
    cin >> n;
    vector < pair < int, int > > kr;
    vector < pair < int, int > > ab;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        kr.pb({x, y});
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ab.pb({x, y});
    }
    map < pair < int, int >, int > cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cnt[{kr[i].fi + ab[j].fi, kr[i].se + ab[j].se}]) {
                cnt[{kr[i].fi + ab[j].fi, kr[i].se + ab[j].se}] = 1;
            } else {
                cnt[{kr[i].fi + ab[j].fi, kr[i].se + ab[j].se}]++;
            }
            if (cnt[{kr[i].fi + ab[j].fi, kr[i].se + ab[j].se}] >= n) {
                cout << kr[i].fi + ab[j].fi << " " << kr[i].se + ab[j].se << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("bridge.in"); fout("bridge.out");
    /// cin >> TN;
    /// =========================================
    while (TN--) solve();
    return 0;
}