#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    string k;
    cin >> k;
    int len = str.size(), l2 = k.size(), ans = 0;
    for (int i=0; i<l2; i++){
        if (k[i] >= 'A' && k[i] <= 'Z'){
            k[i] += 32;
        }
    }
    for (int i=0; i<len; i++){
        string n = str.substr(i, l2);
        for (int i=0; i<l2; i++){
            if (n[i] >= 'A' && n[i] <= 'Z'){
                n[i] += 32;
            }
        }
        if (n == k) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}