#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int main(){
    freopen("woniu.in", "r", stdin);
    freopen("woniu.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        int days = 0;
        int total = 0;
        while(1){
            days++;
            total += 10;
            if (total >= n) {
                cout << days << endl;
                break;
            }
            total -= 5;
            if (total >= n) {
                cout << days << endl;
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}