#include <iostream>
// #include <cstring>
using namespace std;

int main(){
    string str;
    cin >> str;
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 32;
        }
    }
    char s = str[0];
    str += " ";
    int count=0;
    for (int i=0; i<str.size(); i++){
        if (s == str[i]){
            count++;
        } else{
            printf("(%c,%d)", s, count);
            s = str[i];
            count = 1;
        }
    }
    printf("\n");
    return 0;
}