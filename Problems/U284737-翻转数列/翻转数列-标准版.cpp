#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

string origin;
string result;
int length;

struct node{
    string current;
    vector<int> path;
};

queue<node> que;
unordered_map<string, int> vis;

string split(string str, int R){
    string temp, res = "";
    temp = str.substr(0, R);
    reverse(temp.begin(), temp.end());
    res = temp + str.substr(R, sizeof str);
    return res;
}

bool check(string str){
    if (result.size() != length){
        return false;
    }
    for (int i=0; i<length; i++){
        if (result[i] == '#'){
            continue;
        } else if (result[i] != str[i]){
            return false;
        }
    }
    return true;
}

void bfs(string str, int steps){
    que.push((node){str});
    vis[str] = 0;
    while(!que.empty()){
        node front = que.front();
        string current = front.current;
        if (check(current)){
            printf("m = %d\n", vis[current]);
            for (int i=0; i<vis[current]; i++){
                printf("R%d ", front.path[i]);
            }
            if (vis[current] != 0) printf("\n");
            printf("%s\n", current.c_str());
            return;
        }
        for (int i=1; i<=length; i++){
            string newstr = split(current, i);
            if (vis.count(newstr)) continue;
            vis[newstr] = vis[current] + 1;

            node temp = (node){newstr, front.path};
            temp.path.push_back(i);
            que.push(temp);
        }
        que.pop();
    }
    return ;
}

int main(){
    getline(cin, origin);
    getline(cin, result);
    length = origin.size();
    bfs(origin, 0);
    return 0;
}
