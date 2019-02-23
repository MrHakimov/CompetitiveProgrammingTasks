// Author: mr.omti - Muhammadjon Hakimov

#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define LL long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int TN = 1, days_passed = 1;
string st_date, visokosnost;
vector<int> day_cnt;

int day_num(string s){
    if(s == "monday") return 1;
    else if(s == "tuesday") return 2;
    else if(s == "wednesday") return 3;
    else if(s == "thursday") return 4;
    else if(s == "friday") return 5;
    else if(s == "saturday") return 6;
    return 7;
}

int month_num(string s){
    if(s == "january") return 1;
    else if(s == "february") return 2;
    else if(s == "march") return 3;
    else if(s == "april") return 4;
    else if(s == "may") return 5;
    else if(s == "june") return 6;
    else if(s == "july") return 7;
    else if(s == "august") return 8;
    else if(s == "september") return 9;
    else if(s == "october") return 10;
    else if(s == "november") return 11;
    return 12;
}

pair<int, int> check_month(int d){
    int mes = 1, den = 1, pas = 0;
    int i;
    for(i = 0; i < 12; i++){
        pas += day_cnt[i];
        if(pas >= d) break;
    }
    pas -= day_cnt[i];
    pas = d - pas;
    return {pas, i + 1};
}

void solve(){
    days_passed = 1;
    string st, day, p, month;
    cin >> st >> day >> p >> month;
    int dn = day_num(day), mn = month_num(month);
    if(dn >= day_num(st_date)) days_passed += dn - day_num(st_date);
    else days_passed += 7 + dn - day_num(st_date);
    if(st == "first"){
        while(check_month(days_passed).se != mn) days_passed += 7;
        cout << check_month(days_passed).fi << endl;
    }
    else{
        while(check_month(days_passed).se != mn + 1) days_passed += 7;
        days_passed -= 7;
        cout << check_month(days_passed).fi << endl;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	// =========================================
	// fin("input.txt"); fout("output.txt");
	// fin("bootfall.in"); fout("bootfall.out");
	// =========================================
	fin("holidays.in"); fout("holidays.out");
	cin >> TN;
	cin >> st_date >> visokosnost;
	day_cnt = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(visokosnost == "yes") day_cnt[1]++;
    while (TN--) solve();
	return 0;
}