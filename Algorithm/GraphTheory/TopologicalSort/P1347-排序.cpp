#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, ei;
int vertex[26];
int inDegree[26];
int copyDegree[26];
queue<int> ans;
struct perEdge{
    int to;
    int next;
} edge[1000];

void add(int v1, int v2){
    ei += 1;
    v1 -= 'A', v2 -= 'A';
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    copyDegree[v2] += 1;
    return ;
}

int topological_sort(){
    bool flag = 1;
    while(!ans.empty()) ans.pop();
    for (int i=0; i<n; i++) inDegree[i] = copyDegree[i];
    queue<int> que;
    int numbers = 0, cnt = 0;
    for (int i=0; i<n; i++){
        if (inDegree[i] == 0){
            que.push(i);
            cnt += 1;
            if (cnt > 1) flag = 0;
        }
    }
    
    while(!que.empty()){
        int t = que.front();
        ans.push(t);
        que.pop();
        int index = vertex[t];
        int cnt = 0;
        while(index != 0){
            int u = edge[index].to;
            inDegree[u] -= 1;
            if (inDegree[u] == 0){
                que.push(u);
                cnt += 1;
                if (cnt > 1) flag = 0;
            }
            index = edge[index].next;
        }
        numbers += 1;
    }
    
    if (numbers != n) return 0;
    if (flag == 0) return -1;
    return 1;
}

int main(){
    scanf("%d %d\n", &n, &m);
    for (int i=1; i<=m; i++){
        string str;
        cin >> str;
        add(str[0], str[2]);
        int numbers = topological_sort();
        if (numbers == -1) continue;
        if (numbers == 1){
            printf("Sorted sequence determined after %d relations: ", i);
            while(!ans.empty()){
                printf("%c", ans.front() + 'A');
                ans.pop();
            }
            printf(".\n");
            exit(0);
        } else if (numbers == 0) {
            printf("Inconsistency found after %d relations.\n", i);
            exit(0);
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}