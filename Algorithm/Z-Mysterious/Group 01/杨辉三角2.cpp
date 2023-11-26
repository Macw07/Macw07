#include <iostream>
using namespace std;
int main(){
	int arr[105][105]={{1},{1,1}};
	int n;
	cin>>n;
	for(int i=2;i<n;i++){
		arr[i][0]=1;
		for(int j=1;j<=i;j++){
			arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			cout<<arr[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}