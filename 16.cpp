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
const int N = 1001;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    bool blocked[n];
    for (int i = 0; i < n; i++) {
        blocked[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int pos;
        cin >> pos;
        blocked[pos] = 1;
    }
    if (blocked[0]) {
        cout << -1;
        return;
    }
    int lastFree[n];
    for (int i = 0; i < n; i++) {
        lastFree[i] = blocked[i] ? lastFree[i - 1] : i;
    }
    LL a[k];
    LL ans = 1e18;
    for (int i = 1; i <= k; i++) {
        int j = 0;
        bool f = 0;
        LL cnt = 0ll;
        while (j + i < n) {
            cnt++;
            int next = j + i;
            if (lastFree[next] == j) {
                f = 1;
                break;
            }
            j = lastFree[next];
        }
        cnt++;
        cin >> a[i];
        if (!f) {
            ans = min(ans, a[i] * cnt);
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;
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