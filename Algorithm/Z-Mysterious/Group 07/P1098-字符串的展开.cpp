#include <iostream>
#include <algorithm>
using namespace std;

// 一道字符串的判断题目，虽然很简单，但是wsq又是做了好几遍才AC。So sad。
// 最近状态是有多差啊！
int p1, p2, p3;
string str;

int main(){
    cin >> p1 >> p2 >> p3;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        // 判断减号
        if (str[i] == '-'){
            if (str[i-1]+1 == str[i+1]) continue;
            if (str[i+1] <= str[i-1]) {
                cout << str[i]; 
                continue;
            }
            // 两侧同为减号或者两侧同为小写字母
            if (
                (str[i-1] >= '0' && str[i-1] <= '9' && str[i+1] >= '0' && str[i+1] <= '9') || 
                (str[i-1] >= 'a' && str[i-1] <= 'z' && str[i+1] >= 'a' && str[i+1] <= 'z')
                ){
                    if (p3 == 1){
                        for (int j=int(str[i-1])+1; j<int(str[i+1]); j++){
                            char p = j;
                            if (str[i+1] >= '1' && str[i+1] <= '9') p = j;
                            else if (p1 == 2) p -= 32;
                            if (p1 == 3) p = '*';
                            for (int k=0; k<p2; k++) {
                                cout << p;
                            }
                        }
                    } else{
                        for (int j=int(str[i+1])-1; j>int(str[i-1]); j--){
                            char p = j;
                            if (str[i+1] >= '1' && str[i+1] <= '9') p = j;
                            else if (p1 == 2) p -= 32;
                            if (p1 == 3) p = '*';
                            for (int k=0; k<p2; k++) {
                                cout << p;
                            }
                        }
                    }
            } else cout << str[i];
        } else cout << str[i];
    }
    return 0;
}