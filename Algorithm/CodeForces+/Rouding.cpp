#include <iostream>
using namespace std;

int main(){
    // Rouding
    int s, lst;
    cin >> s;
    lst = s%10;
    if (lst > 5){
        s += 10-lst;
    } else{
        s -= lst;
    }
    cout << s;
    return 0;
}