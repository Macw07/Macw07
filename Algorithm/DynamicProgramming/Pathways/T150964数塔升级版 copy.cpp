#include <iostream>
#include <algorithm>
using namespace std;

long long dp[205][205]={}, temp[5]={};

int find_min(){
    if (temp[1] > temp[2]){
        swap(temp[1], temp[2]);
    }
    if (temp[2] > temp[3]){
        swap(temp[2], temp[3]);
    }
    if (temp[1] > temp[2]){
        swap(temp[1], temp[2]);
    }
    return temp[1];
}
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<=2*i; j++){
            cin >> dp[i][j];
        }
    }
    for (int i=n-1; i>=0; i--){
        for (int j=0; j<=2*i; j++){
            temp[1] = dp[i+1][j];
            temp[2] = dp[i+1][j+1];
            temp[3] = dp[i+1][j+2];
            dp[i][j] = dp[i][j] + find_min();
        }
    }
    cout << dp[0][0];
    return 0;
}