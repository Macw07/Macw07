/* 任给两个正整数N、M，求一个最小的正整数a，使得a和(M-a)都是N的因子。 */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    if(n%i==0 && n%(m-i)==0){
        printf("%d",i);
        return 0;
    }
    printf("-1");
    return 0;
}
