#include <iostream>
using namespace std;



int main(){
    int a, b, c, t;
    string str;
    cin >> a >> b >> c >> str;
    int arr[3] = {str[0], str[1], str[2]};
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
    if (b > c){
        t = b;
        b = c;
        c = t;
    }
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
    for (int i=0; i<3; i++){
        if (arr[i] == 'A') printf("%d ", a);
        if (arr[i] == 'B') printf("%d ", b);
        if (arr[i] == 'C') printf("%d ", c);
    }
    return 0;
}