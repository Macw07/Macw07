#include<iostream>
using namespace std;
int fih,fim,sth,stm;
int allcnt;
void cmp(int h,int m){
    if(h<sth) return ;
    if(h>fih) return ;
    if(h == sth && m<stm) return ;
    if(h == fih && m>fim) return ;
    allcnt++;
    return ;
}
int main(){
    int n;
    cin>>n;
    int time[n][2];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d:%d",&x,&y);
        time[i][0]=x;
        time[i][1]=y;
    }
    scanf("%d:%d %d:%d",&sth,&stm,&fih,&fim);
    for(int i=0;i<n;i++){
        cmp(time[i][0],time[i][1]);
    }
    cout<<allcnt;
    return 0;
}