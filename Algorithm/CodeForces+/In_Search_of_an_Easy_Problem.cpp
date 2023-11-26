#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        if (t != 0){
            cout << "HARD";
            return 0;
        }
    }
    cout << "EASY";
    return 0;
}