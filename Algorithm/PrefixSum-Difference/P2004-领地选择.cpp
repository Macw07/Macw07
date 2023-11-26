#include <iostream>
using namespace std;

int n, m, c;
int ans = -0x7f7f7f7f, ans_x, ans_y;
int arr[1005][1005];
int prefix[1005][1005];

int main(){
    cin >> n >> m >> c;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + arr[i][j] - prefix[i-1][j-1];
        }
    }

    for (int i=0; i<=n-c; i++){
        for (int j=0; j<=m-c; j++){
            int sum = prefix[i+c][j+c] - prefix[i][j+c] - prefix[i+c][j] + prefix[i][j];
            if (sum > ans){
                ans = sum;
                ans_x = i + 1;
                ans_y = j + 1;
            }
        }
    }
    cout << ans_x << " " << ans_y << endl;
    return 0;
}