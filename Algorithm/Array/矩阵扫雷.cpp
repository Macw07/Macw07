/* 扫雷游戏是一款十分经典的单机小游戏。在 n 行 m 列的雷区中有一些格子含有地雷，其他格子不含地雷。
现在给出 n 行 m 列的雷区中的地雷分布，要求计算出每个非地雷格周围的地雷格数。
注：一个格子的周围格子包括其上、下、左、右、左上、右上、左下、右下八个方向上与之直接相邻的格子。 */

#include <iostream>
using namespace std;

char arr[100][100] = {};

int main(){
    int n, m;
    cin >> n >> m;
    int count=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            count = 0;
            if (arr[i][j] == '*'){
                cout << "*";
            } else{
                if (arr[i-1][j]=='*' && i-1>=0){
                    count++;
                }
                if (arr[i+1][j]=='*' && i+1<n){
                    count++;
                }
                if (arr[i][j-1]=='*' && j-1>=0){
                    count++;
                }
                if (arr[i][j+1]=='*' && j+1<m){
                    count++;
                }
                if (arr[i+1][j+1]=='*' && i+1<n && j+1<m){
                    count++;
                }
                if (arr[i+1][j-1]=='*' && i+1<n && j-1>=0){
                    count++;
                }
                if (arr[i-1][j+1]=='*' && i-1>=0 && j+1<m){
                    count++;
                }
                if (arr[i-1][j-1]=='*' && i-1>=0 && j-1>=0){
                    count++;
                }
                cout << count;
            }
        }
        cout << endl;
    }
}