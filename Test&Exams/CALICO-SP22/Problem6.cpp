#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int t, n;
char arr[1024][1024];

void dfs(int x, int y, int depth){
    if (depth == 1){
        arr[x][y] = '/';
        arr[x][y+1] = '\\';
        return ;
    }
    dfs(x, y, depth / 2);
    dfs(x + depth / 2, y - depth/2, depth / 2);
    dfs(x + depth / 2, y + depth/2, depth / 2);
    return ;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        memset(arr, ' ', sizeof arr);
        dfs(1, n, n);
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n*4; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}