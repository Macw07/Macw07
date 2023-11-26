#include <iostream>
#include <cmath>
using namespace std;

int n,m,ans;

void dfs(int t,int A,int B){
	if(t>n){
		if(A-B==m){
			ans++;
		}
		return;
	}
	dfs(t+1,A+t,B);
	dfs(t+1,A,B+t);
}

int main(){
	cin>>n>>m;
	dfs(1,0,0);
	cout<<ans; 
	return 0;
} 