#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int sum[105][105];

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            scanf("%d", &sum[i][j]);
            sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            for (int len=ans+1; i + len <= n && j + len <= m; len++){
                int area = len * len;
                int temp = sum[i+len][j+len] - sum[i][j+len] - sum[i+len][j] + sum[i][j];
                if (area == temp) ans = len;
            }
        }
    }
    cout << ans << endl;
    return 0;
}