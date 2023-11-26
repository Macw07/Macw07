#include <iostream>
using namespace std;

int n;
int arr[305][305];
int ans[305];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    ans[2] = arr[1][2];
    for (int i=3, pre=2; i<=n; i++){
        if (arr[pre-1][i] == arr[pre-1][pre] + arr[pre][i]){
            if (ans[pre] > ans[pre-1]){
                ans[i] = ans[pre] + arr[pre][i];
            } else{
                ans[i] = ans[pre] - arr[pre][i];
            }
        } else{
            if (ans[pre] > ans[pre-1]){
                ans[i] = ans[pre] - arr[pre][i];
            } else{
                ans[i] = ans[pre] + arr[pre][i];
            }
        }
        if (arr[i-1][i] != 0) pre = i;
    }
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}