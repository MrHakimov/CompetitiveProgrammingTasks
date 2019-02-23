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
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1) {
        cout << "YES\n0\n";
        return;
    }
    if (min(a, b) > 1) {
        cout << "NO";
        return;
    }
    if (n < 4 && max(a, b) == 1) {
        cout << "NO";
        return;
    }
    vector < vector < bool > > ans(N, vector < bool > (N, 0));
    if (a > 1) {
        for (int i = 0; i < n - a; i++) {
            ans[i][i + 1] = ans[i + 1][i] = 1;
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = 1;
            }
            ans[i][i] = 0;
        }
        for (int i = 0; i < n - b; i++) {
            ans[i][i + 1] = ans[i + 1][i] = 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
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