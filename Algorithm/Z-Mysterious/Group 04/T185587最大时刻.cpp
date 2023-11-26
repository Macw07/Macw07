#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s1;
    int a=0;
    cin >> s1;
    if (s1[0] < '0' || s1[0] > '9'){
        if (s1[1] < '0' || s1[1] > '9'){
            s1[0] = '2';
            s1[1] = '3';
        } else if(s1[1] < '4'){
            s1[0] = '2';
        } else s1[0] = '1';
    } else if (s1[1] < '0' || s1[1] > '9'){
        if (s1[0] == '1'){
            s1[1] = '9';
        } else{
            s1[1] = '3';
        }
    }
    if (s1[3] < '0' || s1[3] > '9'){
        s1[3] = '5';
    }
    if(s1[4] < '0' || s1[4] > '9'){
            s1[4] = '9';
    }
    cout << s1;
    return 0;
}