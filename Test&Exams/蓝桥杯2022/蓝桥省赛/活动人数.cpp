#include <iostream>
#include <cstring>
using namespace std;
#define MAX 10005//常量 

struct  node{
	int to;
	int next;
};

node edge[2*MAX];
int vex[MAX],dp[MAX][2];
int e,ei=1;

void add(int v1,int v2){
	edge[ei].to=v2;
	edge[ei].next=vex[v1];
	vex[v1]=ei++;
}

void dfs(int t){
	int index=vex[t];
	while(index!=-1){
		int to=edge[index].to;
		dfs(to);
		dp[t][0]+=max(dp[to][1],dp[to][0]);//当前不选的最优解=下属选和不选的max 
		dp[t][1]+=dp[to][0];//当前选择=下属不选择 
		index=edge[index].next;
	}
}

int main(){
	cin>>e;
	memset(vex,-1,sizeof(vex));
	for(int i=0;i<e;i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		add(v1,v2);
		dp[v2][1]=w;
	}
	dfs(0);
	cout<<max(dp[0][0],dp[0][1]);//第一个结点选和不选比较 
	return 0;
}
