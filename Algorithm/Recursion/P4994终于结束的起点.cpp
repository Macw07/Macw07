#include <iostream>
using namespace std;

unsigned long long dp[10000005];

int main(){
    long long M;
    cin >> M;
    dp[1] = 1;
    dp[2] = 1;
    for (long long i=3; i<=M*M+5; i++){
        dp[i] = (dp[i-1] + dp[i-2])%M;
        if (dp[i-1] == 0 && dp[i] == 1){
            cout << i-1 << endl;
            break;
        }
    }
    return 0;
}