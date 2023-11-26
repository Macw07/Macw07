// 做这道题我真的无语掉了,为什么符号不算最长单词?
// 因为这个东西我把同样的逻辑换了7个方法写了个遍. :(
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int length=0, temp=0;
    for (int i=0; i<str.size(); i++){
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
            temp++;
        } else{
            temp=0;
        } 
        length = max(temp, length);
    }
    cout << length << endl;
    return 0;
}