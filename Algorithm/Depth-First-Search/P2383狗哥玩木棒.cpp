#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 初步思路，组成一个正方形，说明需要组成四根长度相同的小木棍，不断尝试看看是否可以组成。

int n, m, sum=0;
int arr[1005];
int sticks[5];
bool check;

void dfs(int index){
    if (check) return;  // 如果有一个答案了，就直接退出，不继续寻找了
    if (index == m){
        // 判断四根木棍是否相等
        if (sticks[1] == sticks[2] && sticks[2] == sticks[3] && sticks[3] == sticks[4]){
            check = true;
        }
        return;
    }
    // 剪枝：如果加上这个以后其他几个枝叶不管怎么加都没用，就放弃这一轮
    for (int i=1; i<=4; i++){
        // 四种情况，把这根木棍加到其中一个里面去
        if (sticks[i] + arr[index] > sum / 4) continue;
        sticks[i] += arr[index];
        dfs(index+1);
        sticks[i] -= arr[index];
    }
    return;
}

int main(){
    scanf("%d\n", &n);
    while(n--){
        scanf("%d", &m);
        check = false;
        sum = 0;
        memset(arr, 0, sizeof arr);
        for (int i=0; i<m; i++){
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        // 将数组进行排序，先尝试比较长的木棍
        sort(arr, arr+m, greater<int>());
        if (sum % 4 == 0) dfs(0);
        if (check) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}