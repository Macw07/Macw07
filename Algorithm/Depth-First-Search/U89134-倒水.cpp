#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
int bx, by, bz;
int vis[25][25][25];
int visz[25];

struct node{
    int b1, b2;
};

// 将第一杯水倒入第二杯水。
node pour(int x, int y, int by){
    // printf("%d %d\n", x, y);
    // 能不能全部倒进去
    int tx, ty;
    if (x + y <= by){
        // 倒的进去的话，全都倒进去
        tx = 0, ty = x + y;
    }
    else{
        // 倒不进去。
        tx = x - (by - y);
        ty = by;
    }
    // printf("%d %d\n\n", x, y);
    return (node){tx, ty};
}

void dfs(int x, int y, int z){
    if (x == 0) {
        if (!visz[z]) visz[z] = 1;
    }

    cout << x << " " << y << " " << z << endl;

    node temp = pour(x, y, by);
    if (!vis[temp.b1][temp.b2][z]){
        vis[temp.b1][temp.b2][z] = 1;
        dfs(temp.b1, temp.b2, z);
    }


    temp = pour(y, x, bx);
    if(!vis[temp.b2][temp.b1][z]) {
        vis[temp.b2][temp.b1][z] = 1;
        dfs(temp.b2, temp.b1, z);
    }

    temp = pour(x, z, bz);
    if (!vis[temp.b1][y][temp.b2]){
        vis[temp.b1][y][temp.b2] = 1;
        dfs(temp.b1, y, temp.b2);
    }

    // temp = pour(z, x, bx);
    // if (!vis[temp.b2][y][temp.b1]){
    //     vis[temp.b2][y][temp.b1] = 1;
    //     dfs(temp.b2, y, temp.b1);
    // }
    
    // temp = pour(y, z, bz);
    // if (!vis[x][temp.b1][temp.b2]){
    //     vis[x][temp.b1][temp.b2] = 1;
    //     dfs(x, temp.b1, temp.b2);
    // }

    // temp = pour(z, y, by);
    // if (!vis[x][temp.b2][temp.b1]){
    //     vis[x][temp.b2][temp.b1] = 1;
    //     dfs(x, temp.b2, temp.b1);
    // }

    return ;    
}

int main(){
    cin >> bx >> by >> bz;
    dfs(0, 0, bz);
    for (int i=0; i<=bz; i++){
        if (visz[i]) cout << i << ' ';
    }
    return 0;
}