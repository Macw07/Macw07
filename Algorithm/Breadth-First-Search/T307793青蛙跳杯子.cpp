#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string original, target;

struct node{
    string current;
    int steps;
};

vector<string> vis;
int dx[] = {-3, -2, -1, 1, 2, 3};

bool isVis(string s){
    for (int i=0; i<vis.size(); i++){
        if (s == vis[i]) return true;
    }
    return false;
}

void bfs1(){
    // 初始化 + 标记
    queue<node> que;
    que.push((node){original, 0});
    vis.push_back(original);
    while(!que.empty()){
        node front = que.front();
        string crt = front.current;
        que.pop();
        // 判断是否是结果
        if (crt == target) {
            cout << front.steps << endl;
            return;
        }
        // 如果不是结果的话就尝试跳，反向思考，哪几个位置可以跳到空杯
        int empty = crt.find('*');
        for (int i=0; i<6; i++){
            int cx = empty + dx[i];  // 位置偏移
            if (cx >= 0 && cx < crt.size()){
                string temp = crt;
                swap(temp[cx], temp[empty]);
                if (!isVis(temp)){
                    vis.push_back(temp);
                    que.push((node){temp, front.steps+1});
                }
            }
        }
    }
}

void bfs2(){
    // 初始化 + 标记
    queue<string> que;
    unordered_map<string, int> d;
    que.push(original);
    d[original] = 0;

    while(!que.empty()){
        string front = que.front();
        int dis = d[front];
        que.pop();
        // 判断是否是结果
        if (front == target) {
            cout << dis << endl;
            return;
        }
        // 如果不是结果的话就尝试跳，反向思考，哪几个位置可以跳到空杯
        int empty = front.find('*');
        for (int i=0; i<6; i++){
            int cx = empty + dx[i];  // 位置偏移
            if (cx >= 0 && cx < front.size()){
                string temp = front;
                swap(temp[cx], temp[empty]);
                if (!d.count(temp)){
                    d[temp] = dis + 1;
                    que.push(temp);
                }
            }
        }
    }
}



int main(){
    cin >> original >> target;
    // bfs1();
    bfs2();
    return 0;
}