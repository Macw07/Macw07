/* 一个 n行n列的螺旋矩阵可由如下方法生成：从矩阵的左上角（第1行第1列）出发，
初始时向右移动；如果前方是未曾经过的格子，则继续前进，否则右转；重复上述操作直至经过矩阵中所有格子。
根据经过顺序，在格子中依次填入1,2,3,...,n，便构成了一个螺旋矩阵。 */

#include <iostream>
using namespace std;

int main(){
    int n, target_i, target_j;
    cin >> n >> target_i >> target_j;
    int i, j;
    int start_x = 0, start_y = 0, count=1, offset=1;
    int times = n/2;
    int res[n][n];
    while (times--){
        for (j = start_y; j<n - offset; j++){
            res[start_x][j] = count++;
        }
        for (i = start_x; i<n-offset; i++){
            res[i][j] = count++;
        }
        for (; j > start_y; j--) {
                res[i][j] = count++;
            }
        for (; i > start_x; i--) {
            res[i][j] = count++;
        }
        start_x++;
        start_y++;
        offset++;
    }
    if (n%2){
        res[n/2][n/2] = count;
    }
    
    // for (i=0; i<n; i++){
    //     for (j=0; j<n; j++){
    //         cout << res[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res[target_i-1][target_j-1];
}