#include <iostream>
using namespace std;

int n, m, cnt;
int arr[105][105];

int count_digit(int num){
    int sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            if (count_digit(arr[i][j])%2)
            cnt+=1;
        }
    }
    cout << cnt << endl;
    return 0;
}