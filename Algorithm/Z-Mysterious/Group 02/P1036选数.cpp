#include <iostream>
using namespace std;

int arr[1005] = {};
int total = 0;
int n, k;

bool prime(int n){
    for (int i=2; i*i<=n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int c, int sum, int startindex){  // 设立一个startindex
    // n，代表长度，c代表当前的数字， k代表目标值
    if (c == k){
        if (prime(sum)){
            // cout << sum << " ";
            total += 1;
        }
        return;
    }
    for (int i=startindex; i<n; i++){
        // 深度优先搜索
        dfs(c+1, sum + arr[i], i+1);  // 记住这里是i+1而不是startindex+1
    }
    return;
}

int main(){
    
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0, 0, 0);
    cout << total;
    return 0;
}