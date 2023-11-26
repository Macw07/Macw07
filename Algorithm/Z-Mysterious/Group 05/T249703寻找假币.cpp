#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count=0, sum=1;
    while (true){
        count++;
        sum *= 3;
        if (sum >= n){
            break;
        }
    }
    cout << count << endl;
    return 0;
}