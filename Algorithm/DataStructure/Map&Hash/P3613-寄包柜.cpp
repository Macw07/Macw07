#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, q;
map<int, map<int, int> > locker;

int main(){
    cin >> n >> q;
    for (int index=1; index<=q; index++){
        int t, i, j, k = 0;
        cin >> t;
        if (t == 1) {
            cin >> i >> j >> k;
            locker[i][j] = k;
        } else{
            cin >> i >> j;
            cout << locker[i][j] << endl;
        }
    }
    return 0;
}