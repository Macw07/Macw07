#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
// 这次终于不是一知半解了。

void dfs(int n){
    // 递归的终止条件
    if (n == 0) return ;

    long long temp = n;
    for (int i=log2(n)+1; i>=0; i--){
        long long t1 = pow(2, i);
        if (temp - t1 >= 0){
            if (i == 1) cout << "2";  // 2^1就是二本身，所以特判一下就行了。
            else if (i == 0) cout << "2(0)";  // 分解完了，不需要分解。
            else{
                cout << "2(";  // 继续分解
                dfs(i);
                cout << ")";
            }
            temp -= t1;
            if (temp) cout << "+";
        }
    }

    return ;
}

int main(){
    cin >> n;
    dfs(n);
    return 0;
}