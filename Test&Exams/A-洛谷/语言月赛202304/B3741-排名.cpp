#include <iostream>
#include <algorithm>
using namespace std;

int a1, a2, p1, p2;

int main(){
    cin >> a1 >> p1 >> a2 >> p2;
    if (a1 == a2){
        if (p1 > p2){
            cout << "\"\\t\"";
        } else{
            cout << "\"\\n\"";
        }
    } else{
        if (a1 > a2){
            cout << "\"\\n\"";
        } else{
            cout << "\"\\t\"";
        }
    }
    return 0;
}