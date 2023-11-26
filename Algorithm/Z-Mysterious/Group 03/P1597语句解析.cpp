#include <iostream>
using namespace std;

string x;    //使用字符串 
int a[101]={0};    //初始值为0 
int t; 

int main()
{
    getline(cin, x);
    for (int i=0;x[i]!='\0';i++){  
        if (x[i]>='a'&&x[i]<='z'){   
            if (x[i+3]>='a'&&x[i+3]<='z') a[x[i]-97]=a[x[i+3]-97];
            else t=x[i]-97;
        }
        if (x[i]>='0'&&x[i]<='9') a[t]=x[i]-48;
    }
    printf("%d %d %d", a[0], a[1], a[2]);
}