#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
int arr[10005];
int vis[10005];
vector<int> path;

bool check(){
    for (int i=0; i<4; i++){
        cout << path[i] << " ";
    }
    cout << endl;
    return 1;
}

void dfs(int index){
    if (path.size() == 4){
        if (check()){
            cnt = (cnt + 1) % 1000000007; 
        }
        return;
    }
    for (int i=0; i<n; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            path.push_back(i);
            dfs(i+1);
            path.pop_back();
            vis[i] = 0;
        }
    }
    return;
}
int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0);
    return 0;
}