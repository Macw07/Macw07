/* 已知，公鸡5元一只，母鸡3元一只，小鸡3只一元，百钱买百鸡，问公鸡、母鸡、小鸡各几何？
你的任务是：根据给定的钱数 m，和买到的鸡数 n，输出所有的方案。
如果没有可行方案，输出 None。 */

/* 枚举法两种优化
1. 缩小枚举范围
2. 减少循环层数 */
#include <iostream>
using namespace std;

int main(){
    int m;
    int n;
    cin >> m >> n;
    bool flag = 0;
    for (int i=0; i <= m/5; i++){
        for (int j=0; j <= m/3; j++){
            for (int k=0; k <= m*3; k+=3){
                if ((i+j+k==n) && (5*i + 3*j + k/3 == m)){
                    cout << i << " " << j << " "<< k << endl;
                    flag = 1;
                }
            }
        }
    }
    if (!flag){
        cout << "None" << endl;
    }

}