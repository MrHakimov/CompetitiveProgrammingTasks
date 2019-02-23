// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1;
int n, m;
char arr[55][55];
vector<pair<int, int> > v1, v2;

void rotate(int x, int y){
  if(arr[x + 1][y] == 'U'){
    if(arr[x + 1][y + 1] == 'L') rotate(x + 1, y + 1);
    v2.pb({x + 1, y});
    arr[x + 2][y] = 'L';
    arr[x + 2][y + 1] = 'R';
  }
  v2.pb({x, y});
  arr[x][y] = arr[x][y + 1] = 'U';
  arr[x + 1][y] = arr[x + 1][y + 1] = 'D';
}

void ans(){
  v2.clear();
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        cin >> arr[i][j];
  for(int i = 1; i < n; i++)
    for(int j = 1; j < m; j++)
        if(arr[i][j] == 'L') rotate(i, j);
}

void solve() {
  cin >> n >> m;
  ans();
  v1 = v2;
  ans();
  cout << v1.size() + v2.size() << endl;
  for(int i = 0; i < v1.size(); i++) cout << v1[i].fi << " " << v1[i].se << endl;
  for(int i = v2.size() - 1; i >= 0; i--) cout << v2[i].fi << " " << v2[i].se << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// =========================================
	// fin("input.txt"); fout("output.txt");
	// fin("bootfall.in"); fout("bootfall.out");
	// cin >> TN;
	// =========================================
	while (TN--) solve();
	return 0;
}