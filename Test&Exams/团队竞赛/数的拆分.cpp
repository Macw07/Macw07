#include <iostream>
using namespace std;

int n, total;
int path[25];

void dfs(int n, int dep){
    if (n == 0){
        for (int i=1; i<dep-1; i++) cout << path[i] << "+";
        cout << path[dep-1] << endl;
        total++;
    }
    for (int i=path[dep-1]; i<=n; i++){
        path[dep] = i;
        dfs(n-i, dep+1);
        path[dep] = 0;
    }
    return ;
}

int main(){
    cin >> n;
    path[0] = 1;
    dfs(n, 1);
    cout << "total=" << total << endl;
    return 0;
}