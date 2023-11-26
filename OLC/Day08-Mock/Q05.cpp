#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <unordered_map>
using namespace std;

int t;
string a, b;

struct node{
    string str;
    int steps;
};

void bfs(){
    queue<node> que;
    que.push((node){a, 0});
    unordered_map<string, int> map;
    map[a] = 1;

    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (t.str == b){
            cout << t.steps << endl;
            return ;
        }
        // 对每一位数字进行处理
        for (int i=0; i<4; i++){
            string new_str = t.str;
            if (new_str[i] == '1'){
                new_str[i] += 1;
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
                new_str[i] = '9';
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
            } else if (new_str[i] == '9'){
                new_str[i] -= 1;
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
                new_str[i] = '1';
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
            } else{
                new_str[i] += 1;
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
                new_str[i] -= 2;
                if (map.count(new_str) == 0){
                    map[new_str] = 1;
                    que.push((node){new_str, t.steps + 1});
                }
            }
        }
        for (int i=0; i<3; i++){
            string new_str = t.str;
            swap(new_str[i], new_str[i+1]);
            if (map.count(new_str) == 0){
                map[new_str] = 1;
                que.push((node){new_str, t.steps + 1});
            }
        }
    }
    return ;
}

int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> t;
    while(t--){
        cin >> a >> b;
        bfs();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}