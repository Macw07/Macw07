#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = !(a == 1 && b == 1);
    cout << ans << endl;
    return 0;
}