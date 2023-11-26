#include<iostream>
using namespace std;
int main()
{
    int n,m,a[510],c = 0,b = 0;
    cin >> n >> m;
    for(int i = 1;i<=m;i++)
    {
      cin >> a[i];  
        if(a[i] > n){
            c = 1;
            cout << i <<" ";
        }
    }
    if (c !=0 ) cout << endl;
    if(c == 0)
    {
        cout <<"SO SAD";
    }
    for(int i = 1;i<=m;i++){
        if(a[i] > n * 1.2)
            cout << i <<" ";
    }
    
    return 0;
}