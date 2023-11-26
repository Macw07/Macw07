#include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    t = n;
    for (int j=1; ; j+=n+1){
        for (int i=j; i<j+n; i++){
            if (i<=9){
                cout << 0 << i;
            } else{
                cout << i;
            }
        }
        cout << endl;
        n--;
        if (!n){
            break;
        }
    }
    return 0;
}