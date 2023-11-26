#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;  // 节点的数量
int arr[555];  // 每一个节点的权重
int ans_depth;  // 答案深度值
int max_weight;  // 权重最高的那个数值

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    int i = 1;  // 代表我们从第i个节点开始进行累加。
    int current_depth = 1;  // 当前深度 - 1
    while(i <= n){
        int sum = 0;  // 当前深度的权重总和。
        // 从第i个节点开始，往后累加x个节点权重即可。
        for (int j=1; j<=pow(2, current_depth-1); j++, i++) sum += arr[i];

        if (sum > max_weight){
            max_weight = sum;
            ans_depth = current_depth;
        }
        current_depth += 1;
    }
    cout << ans_depth << endl;
    return 0;
}