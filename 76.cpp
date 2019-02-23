/// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define LD long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1;
int INF = 1e9;

void solve() {
    int n, w;
    cin >> n >> w;
    vector < int > c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
	}
    int mask = (1 << n);
    vector < LL > p(mask, -1);
    vector < pair < int, int > > d(mask, {INF, 0});
    d[0] = {0, w};
    for (int i = 1; i < mask; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) % 2 == 1) {
                int currentMask = i ^ (1 << j), add = 0, currentValue = d[currentMask].se - c[j];
                if (currentValue < 0) {
                    currentValue = w - c[j];
					add++;
				}
                if (d[currentMask].fi + add < d[i].fi || (d[currentMask].fi + add == d[i].fi && currentValue > d[i].se)) {
                    d[i].fi = d[currentMask].fi + add;
                    d[i].se = currentValue;
                    p[i] = j;
                }
            }
        }
    }
    if (d[mask - 1].se < w) {
        cout << d[mask - 1].fi + 1 << endl;
	}
    else {
        cout << d[mask - 1].fi << endl;
	}
    vector < int > ans;
    int copyMask = mask - 1;
    while (p[copyMask] != -1) {
        ans.pb(p[copyMask]);
        copyMask ^= (1 << p[copyMask]);
    }
    reverse(all(ans));
    int currentSum = 0;
    vector < vector <int> > res;
    vector <int> current;
    for (int i = 0; i < ans.size(); i++) {
        if (currentSum + c[ans[i]] > w) {
            res.pb(current);
            currentSum = 0;
            current.clear();
		}
        currentSum += c[ans[i]];
        current.push_back(ans[i] + 1);
    }
    if (current.size() > 0) {
        res.pb(current);
	}
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].size() << " ";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
		}
        cout << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	fin("skyscraper.in"); fout("skyscraper.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}