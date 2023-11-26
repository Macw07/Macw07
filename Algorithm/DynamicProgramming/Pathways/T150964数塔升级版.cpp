#include <iostream>
#include <algorithm>
using namespace std;

int dp[100][205], temp[5];

int main(){
    int n, min;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<1+2*i; j++){
            cin >> dp[i][j];
        }
    }
    for (int i=n-2; i>=0; i--){
        min = 0x7f7f7f;
        for (int j=0; j<1+2*i; j++){
            temp[1] = dp[i+1][j];
            temp[2] = dp[i+1][j+1];
            temp[3] = dp[i+1][j+2];
            for (int k=1; k<=3; k++){
                if(temp[k]<min) min = temp[k];
            }
            // cout << min << endl;
            dp[i][j] += min;
        }
    }
    cout << dp[0][0];
    return 0;
}