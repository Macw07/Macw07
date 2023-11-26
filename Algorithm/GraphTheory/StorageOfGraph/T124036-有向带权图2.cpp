#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, q;

struct node{
    int vertex;
    int length;
};

vector<node> G[100005];

int main(){
    cin >> n >> m >> q;
    for (int i=1; i<=m; i++){
        int x, y, len;
        cin >> x >> y >> len;
        G[x].push_back((node){y, len});
    }
    while(q--){
        int x;
        cin >> x;
        for (int i=G[x].size()-1; i>=0; i--) 
            cout << G[x][i].vertex << " " << G[x][i].length << endl;
    }
    return 0;
}