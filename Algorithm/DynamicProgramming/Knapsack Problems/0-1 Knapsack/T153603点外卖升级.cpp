#include <iostream>
using namespace std;

int dp[10005],v[1005];

int main(){
	int n,w,sum=0,ans=0x7f7f7f7f;
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		sum+=v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			if(j>=v[i]){
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
			}
			if(dp[j]>=w){
				ans=min(ans,dp[j]);//所有超过配送费的最小值 
			}
		}
	}
	cout<<ans;
	return 0;
} 