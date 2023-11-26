#include <iostream>
#include <algorithm>
using namespace std;

/*
备注：这道题目前还有点模棱两可的，博弈论不大会。
*/

int n;
int y, m, d;
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[2007][15][35];
int vis[2007][15][35];

bool check(int year, int month, int day){
    if (year < 2006) return true;
    if (year == 2006 && month < 11) return true;
    if (year == 2006 && month == 11 && day < 4) return true;
    return false;
}

int dfs(int year, int month, int day){
    if ((year%4 != 0 || year == 1900) && month == 2 && day == 29) return 0;
    // 下一个月咯
    if (day > months[month]){
        day = 1;
        month += 1;
    }
    // 第二年喽
    if (month > 12){
        year += 1;
        month = 1;
    }
    if (vis[year][month][day]) return ans[year][month][day];
    vis[year][month][day] = 1;

    if (day <= months[month+1] && check(year, month+1, day)){
        ans[year][month][day] = dfs(year, month+1, day)^1;  // 如果前面可以，那就代表这次不行
    }
    if (check(year, month, day+1)){
        ans[year][month][day] |= dfs(year, month, day+1)^1;
    }

    return ans[year][month][day];
}

int main(){
    cin >> n;
    ans[2006][11][3] = 1;  // base case
    dfs(1900, 1, 1);
    for (int i=0; i<n; i++){
        cin >> y >> m >> d;
        if (ans[y][m][d]){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}