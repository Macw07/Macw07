#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // 初始化
    int h, s, current;
    cin >> h >> s;
    current = s;
    // 模拟
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] == 'u' && current > 0){
            current = max(0, current-1);
        }
        if (str[i] == 'd' && current < h){
            current = min(h, current+1);
        }
    }
    cout << current << endl;
    return 0;
}