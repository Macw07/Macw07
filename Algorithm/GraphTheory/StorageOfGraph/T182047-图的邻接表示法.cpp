#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
struct node{
    int to;
    int next;
} edge[1000];
int vertex[1000], ei = 1;

void add(int v1, int v2){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

int main(){
    cin >> m >> n;
    memset(vertex, -1, sizeof vertex);
    for (int i=1; i<=n; i++){
        int v, u;
        cin >> v >> u;
        add(v, u);
    }
    for (int i=1; i<=m; i++){
        int index = vertex[i];
        cout << i;
        while(index != -1){
            cout << "-> " << edge[index].to;
            index = edge[index].next;
        }
        cout << "-> " << endl;
    }
    return 0;
}