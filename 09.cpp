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

bool A[5201][20801];
int n;

bool can(int x) {
    for (int i = 1; i <= n; i += x) {
        for (int j = 1; j <= n; j += x) {
            for (int a = 0; a < x; a++) {
                for (int b = 0; b < x; b++) {
                    if (A[i][j] != A[i + a][j + b]) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < n / 4; j++) {
            int x;
            if ('0' <= s[j] && s[j] <= '9') {
                x = (int)(s[j] - '0');
            } else {
                x = (int)(s[j] - 'A') + 10;
            }
            A[i][j * 4 + 1] = (x >> 3) & 1;
            A[i][j * 4 + 2] = (x >> 2) & 1;
            A[i][j * 4 + 3] = (x >> 1) & 1;
            A[i][j * 4 + 4] = (x >> 0) & 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (n % i == 0 && can(i)) {
            cout << i << endl;
            return;
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