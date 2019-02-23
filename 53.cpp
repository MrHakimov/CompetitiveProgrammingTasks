/// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define LL long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

int TN = 1, n;
vector < LL > nums;

bool find(LL x) {
    int l = 0, r = n - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(nums[m + 1] <= x) l = m + 1;
        else r = m;
    }
    if(nums[l] == x) return 1;
    return 0;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        nums.pb(x);
    }
    sort(all(nums));
    for(int i = 0; i < n; i++) {
        LL cur = nums[i];
        for(int j = 0; j < 31; j++) {
            LL deg = (1 << j);
            int i1 = find(cur - deg), i2 = find(cur + deg);
            if(i1 && i2) {
                cout << "3\n" << cur - deg << " " << cur << " " << cur + deg << endl;
                return;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        LL cur = nums[i];
        for(int j = 0; j < 31; j++) {
            LL deg = (1 << j);
            int i1 = find(cur + deg);
            if(i1) {
                cout << "2\n" << cur << " " << cur + deg << endl;
                return;
            }
        }
    }
    cout << "1\n" << nums[0] << endl;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	/// =========================================
	/// fin("input.txt"); fout("output.txt");
	/// fin("file.in"); fout("file.out");
	/// cin >> TN;
	/// =========================================
	while (TN--) solve();
	return 0;
}