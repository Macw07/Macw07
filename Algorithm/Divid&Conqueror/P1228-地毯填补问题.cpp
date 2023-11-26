#include <iostream>
#include <algorithm>
using namespace std;
#define ul dfs(zx+l-1, zy+l-1, zx, zy, l);  // 左上角
#define ur dfs(zx+l-1, zy+l, zx, zy+l, l);  // 右上角
#define dl dfs(zx+l, zy+l-1, zx+l, zy, l);  // 左下角
#define dr dfs(zx+l, zy+l, zx+l, zy+l, l);  // 右下角

// 这道题也是模棱两可的做完的，主要就是找分治的感觉。
int k, x, y;

void dfs(int x, int y, int zx, int zy, int l){
    if (l == 1) return ;  // 递归的结束
    l >>= 1;  // 除以2

    // 四个方向：左上角，右上角，左下角，右下角。
    if (x - zx < l && y - zy < l){
        printf("%d %d 1\n", zx+l, zy+l);
        dfs(x, y, zx, zy, l);
        ur
        dl
        dr
    }
    if (x - zx < l && y - zy >= l){
        printf("%d %d 2\n", zx+l, zy+l-1);
        dfs(x, y, zx, zy+l, l);
        ul
        dl
        dr
    }
    if (x - zx >= l && y - zy < l){
        printf("%d %d 3\n", zx+l-1, zy+l);
        dfs(x, y, zx+l, zy, l);
        ul
        ur
        dr
    }
    if (x - zx >= l && y - zy >= l){
        printf("%d %d 4\n", zx+l-1, zy+l-1);
        dfs(x, y, zx+l, zy+l, l);
        ul
        ur
        dl
    }
    return ;
}

int main(){
    cin >> k >> x >> y;
    dfs(x, y, 1, 1, 1 << k);
    return 0;   
}