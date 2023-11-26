#include <iostream>
using namespace std;

int arr[8][8];

bool check(int i, int j){
    bool row=1, column=1;
    // 判断是否是这一行最大的
    for (int a=1; a<=5; a++){
        if (arr[i][j] < arr[i][a]){
            row = 0;
            break;
        }
    }
    for (int a=1; a<=5; a++){
        if (arr[i][j] > arr[a][j]){
            column = 0;
            break;
        }
    }
    return row && column;
}
int main(){
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){
            cin >> arr[i][j];
        }
    }
    // 计算鞍点，只需要判断每一行是不是每一列最大的即可，这是一个暴力解决办法，但是比较方便
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){
            if (check(i, j)) {
                printf("%d %d %d", i, j, arr[i][j]);
                return 0;
            }
        }
    }
    printf("not found");
    return 0;
}