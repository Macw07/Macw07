/* 小 A 有一个质数口袋，里面可以装各个质数。
他从 2 开始，依次判断各个自然数是不是质数，如果是质数就会把这个数字装入口袋。
口袋的负载量就是口袋里的所有数字之和。但是口袋的承重量有限，不能装得下总和超过 L（11≤L≤10^5 ）的质数。
给出 L，请问口袋里能装下几个质数？将这些质数从小往大输出，然后输出最多能装下的质数个数，所有数字之间有一空行。 */

#include<iostream>
using namespace std;
int main()
{
	int L;
	cin>>L;
	if(L>=2)
	{
	int sum=2;
	cout<<2<<endl;
	int m=1;
	for(int i=3;sum<=L&&sum+i<=L;i+=2)
	{
		int k;
		for(k=3;k<i;k+=2)
		{
			if(i%k==0)
				break;
			if(k*k>i)
				break;
		}
		if(k*k>i) 
		{
			sum+=i;
			cout<<i<<endl;
			m++;
		}
	}
	cout<<m;
	}
	else
		cout<<0<<endl;
	return 0;
}
