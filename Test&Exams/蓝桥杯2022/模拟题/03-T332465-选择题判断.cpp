#include <iostream>
#include <algorithm>
using namespace std;

int sum = 0;  // 学生的总分
string ans = "DCBAD";  // 标准答案
string v;  // 学生的做题情况

int main(){
    cin >> v;
    for (int i=0; i<ans.size(); i++){
        if (v[i] == ans[i]) sum += 30;
    }
    cout << sum << endl;
    return 0;
}