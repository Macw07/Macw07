#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length(), temp=1;
    char pre=s[0];
    for (int i = 1; i < len; i++){
        if (s[i] == pre) temp++;
        else{
            printf("%d%c", temp, pre);
            pre = s[i];
            temp = 1;
        }
    }
    printf("%d%c", temp, pre);
    return 0;
}