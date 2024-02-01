#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[100005];

int main(){
    // freopen("Data/testcase15.in", "r", stdin);
    // freopen("Data/testcase15.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    // 找出分割线。
    for (int i=sqrt(n); i>=1; i--){
        if (n % i == 0){
            int another = n / i;
            for (int j=1; j<=another; j++){
                for (int k=j; k<=n; k+=another){
                    cout << arr[k] << " ";
                }
            }
            return 0;
        }
    }
    return 0;
}