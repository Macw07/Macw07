/* 
输入n和m（两者都小于等于100），按照下图对数组进行填充，第一个位置填1，到最后一个填n*m。

4 3
  1   2   4
  3   5   7
  6   8  10
  9  11  12 */

#include <iostream>
using namespace std;
int mat[105][105],n,m,x=0,y=0,num=1;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n+m-1;i++)
	{
		for(int j=0;j<=i;j++)
			if(j<n && i-j<m) mat[j][i-j]=num++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%3d",mat[i][j]);
			if(j<m-1) cout<<" ";
		}	
		if(i<n-1) cout<<endl;
	}
	return 0;
}