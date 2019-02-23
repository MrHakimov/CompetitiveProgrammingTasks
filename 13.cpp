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
    string s;
    cin >> s;
    int n = (int)s.length();
    int st = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '[') {
            st = i;
            break;
        }
    }
    int firstD = -1;
    for (int i = st; i < n; i++) {
        if (s[i] == ':') {
            firstD = i;
            break;
        }
    }
    int ed = -1;
    for (int i = n - 1; i > st; i--) {
        if (s[i] == ']') {
            ed = i;
            break;
        }
    }
    int secondD = -1;
    for (int i = ed - 1; i > firstD; i--) {
        if (s[i] == ':') {
            secondD = i;
            break;
        }
    }
    if (st == -1 || ed == -1 || firstD == -1 || secondD == -1) {
        cout << -1;
        return;
    }
    if (firstD == secondD) {
        cout << -1;
        return;
    }
    if (st == ed) {
        cout << -1;
        return;
    }
    int cnt = 0;
    for (int i = firstD; i < secondD; i++) {
        if (s[i] == '|') {
            cnt++;
        }
    }
    cout << 4 + cnt;
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