#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    // 直接枚举就行了，不需要太多的慰问，稍微处理一些边缘条件
    for (int i=0; i*i<=n; i++){
        for (int j=0; j*j<=n-i; j++){
            for (int k=0; k*k<=n-i-j; k++){
                int l = n-i*i-j*j-k*k;  // 优化枚举
                if (sqrt(l) == double(int(sqrt(l)))){
                    printf("%d %d %d %d", i, j, k, int(sqrt(l)));
                    return 0;
                }
            }
        }
    }
    return 0;
}