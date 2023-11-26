#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        if (temp%2){
            cout << "zs wins\n" ;
        }
        else cout << "pb wins\n";
    }
    return 0;
}