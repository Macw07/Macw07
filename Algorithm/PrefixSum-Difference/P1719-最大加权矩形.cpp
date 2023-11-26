#include <iostream>
using namespace std;

// 二维前缀和模板题
int n, ans;
int arr[150][150];
int prefix[150][150];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + arr[i][j] - prefix[i-1][j-1];
        }
    }

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            for (int k=i+1; k<=n; k++){
                for (int l=j+1; l<=n; l++){
                    int sum = prefix[k][l] - prefix[i][l] - prefix[k][j] + prefix[i][j];
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}