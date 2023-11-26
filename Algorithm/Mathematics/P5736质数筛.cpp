#include <iostream>
using namespace std;

bool prime(int n){
    for (int i=2; i<n; i++){
        if (n%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int n, t;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        if (t == 1){
            continue;
        }
        if(t == 2){
            cout << t << " ";
            continue; 
        }
        if (prime(t)){
                cout << t << " ";
        }
    }
    return 0;
}