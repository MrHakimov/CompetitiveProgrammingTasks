#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector < int > a;
    for (int i = 0; i < n; i++) {
        int currentNumber;
        cin >> currentNumber;
        a.push_back(currentNumber);
    }
    sort(a.begin(), a.end());
    int numberOfQueries;
    cin >> numberOfQueries;
    for (int query = 0; query < numberOfQueries; query++) {
        int left, right;
        cin >> left >> right;
        int l = 0, r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] >= left) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (r == n - 1 && a[r] < left) {
            cout << 0 << " ";
            continue;
        }
        if (l < r && a[l] >= left) r = l;
        int start = r;
        l = 0; r = n - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m] <= right) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        if (l == 0 && a[l] > right) {
            cout << 0 << " ";
            continue;
        }
        if (r > l && a[r] <= right) l = r;
        int end = l;
        if (end < start) {
            cout << 0 << " ";
            continue;
        }
        cout << end - start + 1 << " ";
    }
	return 0;
}