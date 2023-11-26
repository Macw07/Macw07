#include <iostream>
using namespace std;

int main(){
    int n, k, b, cnt=0;
    cin >> n >> k >> b;
    while(n--){
        int x, y;
        cin >> x >> y;
        if (y == k*x + b) cnt++;
    }
    cout << cnt << endl;
    return 0;
}