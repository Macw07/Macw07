// 输入一串字符串，输出需要在九宫格打多少次才可以。

#include <iostream>
using namespace std;
int ans;
string a;
int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4}; 
int main()
{
    getline(cin,a);
    for(int i=0;i<a.length();i++)
        {
            if(a[i]>='a'&&a[i]<='z') {
                ans+=num[a[i]-'a'];
            }
            if(a[i]==' '){
                ans++;
            } 
        }
    printf("%d",ans);
    return 0;
}