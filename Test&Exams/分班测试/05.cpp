#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t;
int total;

string convert(int t){
    string a;
    while(t){
        a += (t % 10) + '0';
        t /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}

int main(){
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int len = str.size(), m = pow(10, len);
        total = 0;
        for (int i=pow(10, len-1); i<=m; i++){
            string k = convert(i);
            bool flag = 1;
            if (k.size() != len) continue;
            for (int i=0; i<len; i++){
                if (str[i] == '?') continue;
                if (str[i] != k[i]){
                    flag = 0;
                    break;
                }
            }
            if (flag) total += 1;
        }   
        cout << total << endl;
    }
    return 0;
}