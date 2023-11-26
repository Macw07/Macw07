#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
	int n,m,sum=0,idx=0,k=0;
	string str;
	char s[65];
	cin>>n>>str>>m;
	int len=str.size();
	for(int i=len-1;i>=0;i--){
		if(str[i]>='A'){
			sum+=(str[i]-55)*pow(n,k); 
		}else{
			sum+=(str[i]-48)*pow(n,k);
		}
		k++;
	} 
	while(sum){
		if(sum%m>9){
			s[idx++]=sum%m+55;
		}else{
			s[idx++]=sum%m+48;
		}
		sum/=m;
	} 
	for(int i=idx-1;i>=0;i--){
		cout<<s[i];
	}
	return 0;
}
