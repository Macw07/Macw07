#include <iostream>
#include <algorithm>
using namespace std;

int day, a, b;

int main(){
    cin >> a >> b;
    while(a != b){
        a -= 1;
        b = max(2, b-1);
        day += 1;
    }
    cout << day + 1 << endl;
    return 0;
}