#include <iostream>
#include <cmath>
using namespace std;

int n, target;
string num;

// 模板题目

int convert10(string origin, int base){
    int number = 0, k = 0;
    for (int i=origin.size()-1; i>=0; i--){
        if (origin[i] >= 'A') {
            number += (origin[i] - '@' + 9) * pow(base, k);
        } else number += (origin[i] - '0') * pow(base, k);
        k++;
    }
    return number;
}

string backconvert(int origin, int base){
    string ans;
    while(origin){
        int add = origin % base;
        if (add >= 10){
            ans += (add%10) + 'A';
        } else ans += add + '0';
        origin /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cin >> n >> num >> target;
    // 先转换成十进制，再转换回来
    int temp_num = convert10(num, n);
    cout << backconvert(temp_num, target) << endl;
    return 0;
}