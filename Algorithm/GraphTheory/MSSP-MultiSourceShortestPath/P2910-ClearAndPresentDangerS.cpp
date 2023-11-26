#include <iostream>
#include <algorithm>
using namespace std;

// 真的服了，这是什么破题目翻译，看了很久都看不懂。
// 最后还是通过看代码才看懂题目的。

int n, m;
int arr[100005];
int map[105][105];

void floyd(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++) scanf("%d", &arr[i]);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            scanf("%d", &map[i][j]);
        }
    }
    floyd();
    int ans = 0;
    for (int i=2; i<=m; i++){
        ans += map[arr[i-1]][arr[i]];
    }
    printf("%d", ans);
    return 0;
}