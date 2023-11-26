#include <iostream>
using namespace std;

bool vis[15];
int ans[15];

int merge(int l, int r){
    int sum = 0;
    for (int i=l; i<=r; i++){
        sum = sum*10 + ans[i];
    }
    return sum;
}

void dfs(int n){
    if (n > 9){
        int a = merge(1, 3);
        int b = merge(4, 6);
        int c = merge(7, 9);
        // printf("%d %d %d\n", a, b, c);
        if (a*2 == b &&  b*3 == c*2){
            printf("%d %d %d\n", a, b, c);
        }
        return;
    }
    for (int i=1; i<=9; i++){
        if (!vis[i]){
            vis[i] = 1;
            ans[n] = i;
            dfs(n+1);
            vis[i] = 0;
        }
    }
}

int main(){
    dfs(1);
    // printf("192 384 576\n219 438 657\n273 546 819\n327 654 981");
    return 0;
}
