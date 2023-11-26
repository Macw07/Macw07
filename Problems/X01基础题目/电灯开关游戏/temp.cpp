#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int cnt[5054]={1};
    for (int i=1; i<=n; i++) cnt[i] = 1;
    for(int i=1;i<=m;i++){
		int k;
        cin>>k;
        if(cnt[k]==0) cnt[k]=1;
        else if(cnt[k]==1) cnt[k]=0;
        if(cnt[k+1]) cnt[k+1]=0;
        else cnt[k+1]=1;
        if(cnt[k-1]) cnt[k-1]=0;
        else cnt[k-1]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++){
		if(cnt[i]) sum++;
    }
    cout<<sum;
    return 0;
}