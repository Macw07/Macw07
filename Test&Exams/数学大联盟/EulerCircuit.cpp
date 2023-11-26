#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int ans = 0, cnt=0;
int n;
int vis[100][100];
vector<int> path;

int poweradd(int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        sum += i;
    }
    return sum;
} 

// current is current node
void dfs(int current, int steps){

    if (current == 1 && steps == poweradd(n)-(n/2)){
        cnt++;
        // if (cnt % 10 == 0){
            for (int i=0; i<path.size(); i++){
                cout << path[i] << "->";
            }
            cout << endl;
        // }
        return;
    };
    // traverse every adjecent node
    bool flag = false;  // if there is an availiable path to go
    for (int i=1; i<=n; i++){
        if (vis[current][i] || vis[i][current] || current == i) continue;  // if the path is visited
            path.push_back(i);
            vis[current][i] = 1;
            vis[i][current] = 1;
            dfs(i, steps+1);
            flag = true;
            vis[current][i] = 0;
            vis[i][current] = 0;
            path.pop_back();
    }
    return;
}

int main(){
    cin >> n;   
    path.push_back(1);
    dfs(1, 0);
    cout << cnt << endl;
    
    return 0;
}