#include <iostream>
#include <algorithm>
using namespace std;

// 树状数组比我想象的要难，感觉要学很久...

int n, m;
int arr[5000005];

int lowbit(int k){
    // return k & (~k + 1);
    return k & (-k);
}

void add(int position, int k){
    while(position <= n){
        arr[position] += k;
        position += lowbit(position);
    }
}

int query(int k){
    int sum = 0;
    while(k){
        sum += arr[k];
        k -= lowbit(k);
    }
    return sum;
}

int main(){
    int k, x, y;
    scanf("%d %d", &n, &m);
    // 初始化
    for (int i=1; i<=n; i++){
        scanf("%d", &k);
        add(i, k);
    }
    // 修改以及查询操作
    for (int i=1; i<=m; i++){
        scanf("%d %d %d", &k, &x, &y);
        if (k == 1) add(x, y);
        else cout << query(y)-query(x-1) << endl;
    }
    return 0;
}