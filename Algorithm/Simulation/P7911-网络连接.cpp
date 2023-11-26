#include <iostream>
#include <unordered_map>
using namespace std;

// 真的是服了这道题了，要考虑的东西又是一堆。
// 最讨厌的就是字符串处理的题目，每次都需要考虑多种情况。

int n;
unordered_map<string, int> map;

bool check(string address){
    int len = address.size();
    int comma = 0, colon = 0, k = 0;
    long long current_num = 0;
    bool flag = 0;
    for (int i=0; i<len; i++){
        if (address[i] == '.' || address[i] == ':'){
            if (!(current_num >= 0 && current_num <= 255)) return false;
            if (k == 0) return false;
            flag = 0; k = 0;
            // cout << current_num << endl;
            current_num = 0;
            if (address[i] == '.') comma += 1;
            else colon += 1;
        }
        if (address[i] != '.' && address[i] != ':'){
            if (flag == 1) return false;
            if (address[i] == '0' && (i == 0 || address[i-1] == '.' || address[i-1] == ':')) flag = 1;
            k += 1;
            current_num = current_num * 10 + (address[i]-'0');
        }
    }  
    // cout << current_num << endl;
    if (k == 0) return false;
    if (!(current_num >= 0 && current_num <= 65535)) return false;
    return comma == 3 && colon == 1;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        string op, ad;
        cin >> op >> ad;
        if (!check(ad)){
            cout << "ERR" << endl;
            continue;
        }
        if (op == "Server"){
            int k = map.count(ad);
            if (k != 0) cout << "FAIL" << endl;
            else {
                cout << "OK" << endl;
                map[ad] = i;
            }
        } else{
            int k = map.count(ad);
            if (k == 0) cout << "FAIL" << endl;
            else cout << map[ad] << endl;
        }
    }
    return 0;
}