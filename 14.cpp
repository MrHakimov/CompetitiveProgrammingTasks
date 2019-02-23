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
const LD eps = 0.0000001;

void solve() {
    LD n;
    cin >> n;
    if (n == 0) {
        cout << "Y " << 0 << " " << 0 << endl;
        return;
    }
    if (n < 4) {
        cout << "N\n";
        return;
    }
    LD a = (n + sqrt(n * n - 4 * n)) / 2.0;
    LD b = n - a;
    cout << fixed << setprecision(12) << "Y " << a << " " << b << endl;
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