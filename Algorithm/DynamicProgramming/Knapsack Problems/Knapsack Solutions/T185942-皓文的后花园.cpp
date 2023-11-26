#include <iostream>
using namespace std;

int n;
int dp[1005];
int arr[] = {0, 3, 7};

int main(){
    cin >> n;
    dp[0] = 1;
    for (int i=1; i<=2; i++){
        for (int j=0; j<=n; j++){
            if (j >= arr[i]){
                dp[j] += dp[j-arr[i]];
            }
        }
    }
    if (dp[n]){
        cout << "Yes" << endl;
    } else cout << "No" << endl;
    return 0;
}