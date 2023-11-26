#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long dp[205][205];

int fmax(int a, int b, int c){
    if (a > b){
        swap(a, b);
    }
    if (b > c){
        swap(b, c);
    }
    if (a > b){
        swap(a, b);
    }
    return c;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
            dp[i][j] += fmax(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]);
        }
    }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int mid = m/2;
    cout << fmax(dp[n][mid], dp[n][mid+1], dp[n][mid+2]);
    return 0;
}