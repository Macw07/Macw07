#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// 可爱的小marco这辈子第一次不看题解写出属于自己的深搜!
vector<int> path;
int n, r;

void dfs(int startindex){
    if (path.size() == r){
        for (int i=0; i<r; i++){
            cout << setw(3) << path[i];
        }
        cout << endl;
        return;
    }
    for (int i=startindex; i<=n; i++){
        path.push_back(i);
        dfs(i+1);
        path.pop_back();
    }
    return;
}

int main(){
    cin >> n >> r;
    dfs(1);
    return 0;
}