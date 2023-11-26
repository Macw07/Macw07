#include <iostream>
#include <cmath>
using namespace std;

double n, m;
long long squares;  // 记录正方形的个数。
long long rectangles;  // 记录长方形的个数。

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            long long number = (n-i+1) * (m-j+1);
            // 如果是一个正方形的话：
            if (i == j){
                squares += number;
            } else{  // 如果是一个长方形的话：
                rectangles += number;
            }
        }
    }
    cout << squares << " " << rectangles << endl;
    return 0;
}
