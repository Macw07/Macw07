#include <iostream>
#include <algorithm>
using namespace std;

string multiply(string a, string b){
    int arr[1000005] = {};
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // 各位相乘
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<b.size(); j++){
            arr[i+j] += (a[i]-'0')*(b[j]-'0');
        }
    }
    // for (int i=0; i<a.size()+b.size()-1; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // 匀一匀
    for (int i=0; i<=a.size()+b.size(); i++){
        arr[i+1] += arr[i]/10;
        arr[i] %= 10;
    }
    // 输出
    bool flag = 1;
    string s;
    for (int i=a.size()+b.size()-1; i>=0; i--){
        if (flag && arr[i] == 0){
            continue;
        }
        flag = 0;
        s += arr[i]+'0';
    }
    return s;
}

int main(){
    string a, b;
    cin >> a >> b;
    if (a == "0" || b == "0"){
        cout << 0;
        return 0;
    }
    cout << multiply(a, b);
    return 0;
}