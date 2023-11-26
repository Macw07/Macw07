// 优秀的拆分 P7071 [CSP-J2020] 优秀的拆分
// 题目有点难、回去刺激好好琢磨一下。
#include <iostream>
using namespace std;
int n;
long long a[30];
int main(){
	cin>>n;
	if(n%2==1){
		cout<<"-1";
		return 0;
	}
	a[1]=1;
	for(int i=2;i<=26;i++){
		a[i]=a[i-1]*2;
	}
	for(int i=26;i>=2;i--){
		if(n>=a[i]){
			n-=a[i];
			cout<<a[i]<<' ';
		}
		if(n==0)return 0;
	}
	return 0;
} 