#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
char vertexs[10005];
vector<int> G[10005];


int main(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> vertexs[i];
    for (int j=1; j<=m; j++){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
    }
    for (int i=1; i<=k; i++){
        int x; cin >> x;
        sort(G[x].begin(), G[x].end());
        for (int j=0; j<G[x].size(); j++) cout << vertexs[G[x][j]] << ' ';
        if (G[x].size()) cout << endl;
        else cout << "none" << endl;
    }
    return 0;
}