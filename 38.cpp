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
    int n;
    cin >> n;
    int h = 0, w = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int hi, wi;
        cin >> hi >> wi;
        if (wi > hi) {
            swap(hi, wi);
        }
        if (c == '+') {
            if (hi > h || wi > w) {
                h = max(hi, h);
                w = max(wi, w);
                if (w > h) {
                    swap(h, w);
                }
            }
        } else if (c == '?') {
            if (h <= hi && w <= wi || h <= wi && w <= hi) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
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