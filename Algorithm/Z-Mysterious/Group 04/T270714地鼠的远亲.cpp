#include <iostream>
#include <cmath>
using namespace std;

long long arr[55][55];
int n, m;

long long max(long long a, long long b){
    if (a > b){
        return a;
    } else{
        return b;
    }
}

long long find(int a, int b){
    bool check=0;
    long long dis=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if ((a!=i || j!=b) && arr[a][b] == arr[i][j]){
                if (check == 0){
                    check = 1;
                    dis = abs(pow(i-a, 2)+pow(j-b, 2));
                } else{
                    // 计算距离
                    dis = max(dis, abs(pow(i-a, 2)+pow(j-b, 2)));
                }  
            }
        }
    }
    if (check == 1){
        return dis;
    }
    return 0;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    // 寻找亲戚
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            // 找到亲戚的坐标,如果坐标为-1, -1就是没有亲戚.
            cout << find(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}