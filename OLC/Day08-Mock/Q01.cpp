#include <iostream>
using namespace std;

int main(){
    freopen("ikun.in", "r", stdin);
    freopen("ikun.out", "w", stdout);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = a + b + c + d;
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}