#include<iostream>
using namespace std;
int main(){
    freopen("testcase001.in", "r", stdin);
  	// freopen("buy.out", "w", stdout);
    int n,m;
    cin>>n>>m;
    int cnt[5010]={0};
    for(int i=1;i<=n;i++){
        cin>>cnt[i];
    }
    for(int l=1;l<=m;l++){
        int k;
        cin>>k;
        int sum=0;
        for(int i=1;i<=k;i++){
            int a;
            cin>>a;
            sum+=cnt[a];
            cnt[a]=-1;
        }
        cout<<sum<<" ";
        for(int i=1;i<=n;i++){
            while(cnt[i]==-1){
                for(int j=i+1;j<=n;j++){
                    cnt[j-1]=cnt[j];
                }
                n--;
            }
        }
    }
    fclose(stdin);
	fclose(stdout);
    return 0;
}