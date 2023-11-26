#include <iostream>
using namespace std;

int main(){
    int n, m, total = 0;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int t;
            cin >> t;
            // 判断是否是矩阵边缘 i==1 || j==1 || i==n || j==m
            if (i==1 || j==1 || i==n || j==m){
                total += t;
            }
        }
    }
    cout << total << endl;
    return 0;
}