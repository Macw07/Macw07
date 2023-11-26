#include <iostream>
using namespace std;

// 这一题就是纯粹的模拟题，稍微模拟一下就行了

int main(){
    int n;
    cin >> n;
    int drinks = n, top = n;
    while(top/3){
        drinks += top/3;
        int t = top/3;
        top = top%3;
        top += t;
    }
    cout << drinks << endl;
    return 0;
}