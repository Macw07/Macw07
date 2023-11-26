#include <iostream>
using namespace std;

int n,cnt;
int ans[15];
bool st[15];

int get_num(int l,int r)
{
    int sum=0;
    for(int i=l; i<=r; i++)
        sum=sum*10+ans[i];
    
    return sum;
}

void dfs(int u){
    if(u>9){
        for(int i=1; i<=7; i++) {
            for(int j=i+1; j<=8; j++){
                int a,b,c; //第二步
                a=get_num(1,i);
                b=get_num(i+1,j);
                c=get_num(j+1,9);
                if(a*c+b==n*c) //第三步
                    cnt++;
            }
        }
        
        return ;
    }
    
    for(int i=1; i<=9; i++) {
        if(!st[i]){
            st[i]=true;
            ans[u]=i;
            dfs(u+1);
            st[i]=false;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    cout<<cnt;
}
