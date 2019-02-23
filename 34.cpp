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
LD eps = 1e-7;
LD PI = 3.14159265;

void solve() {
    int n, R;
    cin >> n >> R;
    LD l = 0.0, r = 10000.0;
    while (r - l > eps) {
        LD m = (l + r) / 2.0;
        if (m / sin(PI / n) <= m + R) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(15) << l;
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