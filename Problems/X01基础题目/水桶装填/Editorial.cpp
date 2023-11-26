#include <iostream>
using namespace std;

int n, m;
int total;

int main(){
    cin >> n >> m;
    while(m--){
        int t;
        cin >> t;
        total += t;
        if (total > n){
            cout << "Overflows" << endl;
            return 0;
        }
    }
    cout << "Unspilled" << endl;
    return 0;
}