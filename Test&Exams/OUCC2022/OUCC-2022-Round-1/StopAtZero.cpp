#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        for (int i=0; i<n; i++){
            cout << '-';
        }
        cout << endl;
    }
    return 0;   
}