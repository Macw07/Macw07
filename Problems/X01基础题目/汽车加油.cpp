#include <iostream>
using namespace std;

int main(){
    int n, m, total = 0;
    int min = 2147483647, min_location = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int t;
        cin >> t;
        if (t < min){
            min = t;
            min_location = i;
        }
        if (t <= m){
            total += 1;
        }
    }
    if (total == 0){
        cout << 0 << endl;
        cout << "So Sad" << endl;
    } else{
        cout << total << endl;
        cout << min_location << endl;
    }
    return 0;
}