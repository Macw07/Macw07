#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 服了这道题了，明明这么简单，但还是错了很多次，真觉得最近脑子废掉了。 So Sad
int n, m;
int arr[550][550];
int temp[550][550];

void rotate(int x, int y, int r, int z){
    // 数组旋转
    if (z == 0){
        for (int i=x-r; i<=x+r; i++){
            for (int j=y-r; j<=y+r; j++){
                temp[x-y+j][x+y-i] = arr[i][j];
            }
        }
    } else{
        for (int i=x-r; i<=x+r; i++){
            for (int j=y-r; j<=y+r; j++){
                temp[x+y-j][y-x+i] = arr[i][j];
            }
        }
    }
    for (int i=x-r; i<=x+r; i++){
        for (int j=y-r; j<=y+r; j++){
            arr[i][j] = temp[i][j];
        }
    }
    return ;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            arr[i][j] = n*(i-1)+j;
        }
    }

    for (int i=1; i<=m; i++){
        int x, y, r, z;
        scanf("%d %d %d %d", &x, &y, &r, &z);
        rotate(x, y, r, z);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}