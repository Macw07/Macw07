#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt = 0;
int arr[505][505];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (i-1 > 0){
                if (arr[i-1][j] == arr[i][j]) cnt++;
            } 
            if (j-1 > 0){
                if (arr[i][j-1] == arr[i][j]) cnt++;
            }
            if (i+1 <= n){
                if (arr[i+1][j] == arr[i][j]) cnt++;
            }
            if (j+1 <= m){
                if (arr[i][j+1] == arr[i][j]) cnt++;
            }
        }
    }
    cout << cnt/2 << endl;
    return 0;
}