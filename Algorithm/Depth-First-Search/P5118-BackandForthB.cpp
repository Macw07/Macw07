#include <iostream>
using namespace std;

int ans = 0;
int arr1[15], arr2[15];
int p1 = 1000, p2 = 1000;
int vis[3005];

void dfs(int day){
    if (day > 2){
        if (vis[p1] == 0){
            // cout << p1 << endl;
            vis[p1] = 1;
            ans += 1;
        }
        return ;
    }
    // 对于每一个day组，交换两个桶并将桶倒入对方挤奶棚的奶罐中。
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            int copyP1 = p1, copyP2 = p2;

            p1 -= arr1[i]; p2 += arr1[i];
            p2 -= arr2[j]; p1 += arr2[j];

            swap(arr1[i], arr2[j]);
            dfs(day + 1);
            swap(arr1[i], arr2[j]);

            p1 = copyP1, p2 = copyP2;
        }
    }
    return ;
}

int main(){
    for (int i=1; i<=10; i++) scanf("%d", &arr1[i]);
    for (int i=1; i<=10; i++) scanf("%d", &arr2[i]);
    dfs(1);
    cout << ans << endl;
    return 0;
}