#include<iostream>
using namespace std;
long long arr[100005] = {0, 1, 2, 4, 7};

int main(){
	int n;
	cin>>n;
	for(int i=5;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2]+arr[i-4];
	}
	cout<<arr[n];
	return 0;
} 