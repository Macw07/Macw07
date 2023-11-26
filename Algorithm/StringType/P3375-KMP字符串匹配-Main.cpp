/* 真刺激啊，KMP算法 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
说真的，KMP需要考虑的东西实在太多了。
真的很多，很多，很多。
我真的不知道要什么时候才能记住这东西。
但我希望，以后每一次字符串匹配都用一次KMP算法的话，很快就会学会了。
*/

int prefix[10000005];

void move_prefix_table(string str){
    for (int i=str.size(); i>0; i--){
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
    return ;
}

void create_prefix(string str){
    int i = 1, len = 0;
    int n = str.size();
    prefix[0] = 0;
    while(i < n){
        if (str[i] == str[len]){
            len++;
            prefix[i] = len;
            i++;
        }
        else{
            if (len > 0) len = prefix[len-1];
            else {
                prefix[i] = 0;
                i++;
                len = 0;
            }
        }
    }
    move_prefix_table(str);
    return ;
}

void kmp(string s1, string s2){
    create_prefix(s2);
    int i = 0, j = 0;
    int m = s1.size();
    int n = s2.size();
    while(i < m){
        if (j == n-1 && s1[i] == s2[j]){
            cout << (i-j+1) << endl;
        }
        if (s1[i] == s2[j]){
            i++;
            j++;
        } else{
            j = prefix[j];
            if (j == -1) {
                j++;
                i++;
            }
        }
    }
    return ;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    kmp(s1, s2);

    for (int i=1; i<=s2.size(); i++) cout << prefix[i] << " ";
    cout << endl;
    return 0;
}