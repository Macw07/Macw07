#include <iostream>
#include <queue>
using namespace std;

int n, m, ei;
int a, b;
struct perEdge{
	int to;
	int next;
} edge[100005];
int vertex[105];
int dis[105];

void add(int v1, int v2){
	ei += 1;
	edge[ei].to = v2;
	edge[ei].next = vertex[v1];
	vertex[v1] = ei;
	return ;
}

struct node{
	int distance;
	int point;
	bool friend operator < (node a, node b){
		return a.distance > b.distance;
	}
};

void dijkstra(int start, int end){
	for (int i=1; i<=n; i++) dis[i] = 2147483647;
	dis[start] = 0;
	priority_queue<node> que;
	que.push((node){0, start});

	while(!que.empty()){
		node t = que.top();
		que.pop();
		int index = vertex[t.point];
		while(index != 0){
			int u = edge[index].to;
			if (dis[t.point] + 1 < dis[u]){
				dis[u] = dis[t.point] + 1;
				que.push((node){dis[u], u});
			}
			index = edge[index].next;
		}
	}
	return ;
}

int main(){
	// freopen("magic.in", "r", stdin);
	// freopen("magic.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		add(v1, v2);
	}
	cin >> a >> b;
	dijkstra(a, b);
	if (dis[b] == 2147483647) cout << -1 << endl;
	else cout << dis[b] << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}