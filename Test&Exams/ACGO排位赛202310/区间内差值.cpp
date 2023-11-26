#include <iostream>
#include <algorithm>
using namespace std;

int n, mini = 0x7f7f7f7f;
int arr[100005];

int main(){
	cin >> n;
    for (int i=1; i<=n; i++){
    	cin >> arr[i];
    }
    for (int i=1; i<=n-1; i++){
    	mini = min(mini, abs(arr[i]-arr[i+1]));
    }
    cout << mini << endl;
	return 0;
}