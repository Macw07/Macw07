#include <iostream>
#include <cmath>
using namespace std;
int l, r;
bool check1(int x)
{
	if((1000 <= x && x <= 9999) || (100000 <= x && x <= 999999)) return 0;
	return 1;
} 
bool check2(int x)
{
	int a[20], flag = 1;
	while (x > 0)
	{
		a[flag] = x % 10;
		x /= 10;
		flag++;
	} 
	for (int i = 1; i <= flag / 2; i++)
		if(a[i] != a[flag-i]) return 0;
	return 1;
} 
bool check3(int x)
{
	if(x == 2) return 1;
	for(int i = 2; i <= sqrt(x); i++)
		if(x % i == 0) return 0;
	return 1;
}
int main()
{
	scanf("%d %d", &l, &r);
	if(l == 2) printf("2\n");
	if(l % 2 == 0) l++; 
	r = min(9999999, r);
	for(int i = l; i <= r; i = i + 2)
	{
		if(check1(i) == 0) continue;
		if(check2(i) == 0) continue;
		if(check3(i) == 0) continue;
		printf("%d\n", i);
	}	
	return 0;
}