#include <iostream>
#include <queue>
using namespace std; 

int r,c; 
int maps[2001][2001]; 
int vis[2001][2001]; 
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}}; 
struct node{
    int x, y, step; 
};

// 直接输出答案即可，一次性将所有的初始起点加入队列。
queue<node> que;
void bfs(){
    while(que.size()){ 
        node now = que.front(); 
        que.pop(); 
        // cout << now.x << " " << now.y << endl;
        // cout << maps[now.x][now.y] << " ";
        if(maps[now.x][now.y] == -1){   // 判断答案。
            cout << now.step << endl;
            exit(0);  // 直接结束程序。
        } 
        for(int i=0;i<4;i++){ 
            node t = now; 
            t.x += dir[i][0];  
            t.y += dir[i][1];  
            if(t.x<1 || t.y<1 || t.x>r || t.y>c) continue; 
            if(vis[t.x][t.y] || maps[t.x][t.y] == 1) continue;
            vis[t.x][t.y]=1; 
            t.step++; 
            que.push(t); 
        }  
    } 
    return ;
}

int main(){ 
    cin >> r >> c; 
    for(int i=1;i<=r;i++){ 
        for(int j=1;j<=c;j++){ 
            cin >> maps[i][j]; 
        } 
    } 
    int s, e;
    cin >> s;
    // 输入的坐标是从0开始的。
    while(s--){
        int x, y;
        cin >> x >> y;
        x++, y++;
        que.push((node){x, y, 0});
    }
    cin >> e;
    while(e--){
        int x, y;
        cin >> x >> y;
        x++, y++;
        maps[x][y] = -1;  // 记录终点位置。
    }

    bfs();
    return 0; 
}