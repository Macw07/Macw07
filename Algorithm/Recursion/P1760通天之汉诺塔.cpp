#include <iostream>
#include <algorithm>

using namespace std;
int n,l,i,a[10000]; 

void p(){ 
	for(int i=1;i<=l;i++)a[i]*=2;  
	for(int i=1;i<=l;i++)
		if(a[i]>9){
			a[i+1]++;
			a[i]-=10; 
		}
	if(a[l+1]>0)l++;
}
int main(){
	cin>>n;
	a[1]=1;
	l=1; 
	for(i=0;i<n;i++)p();
	for(i=l;i>1;i--)cout<<a[i]; 
	cout<<a[1]-1;
	return 0;
} 