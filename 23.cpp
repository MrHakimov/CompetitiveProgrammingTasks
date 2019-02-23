/// author: Mr.Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define LL long long
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1;

void solve() {
    LL n;
    cin >> n;
    set < LL > ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            LL an = 1 + i * (n / i - 1);
            ans.insert((1 + an) * (n / i) / 2);
            an = 1 + (n / i) * (i - 1);
            ans.insert((1 + an) * i / 2);
        }
    }
    for (auto el: ans) {
        cout << el << " ";
    }
    cout << endl;
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