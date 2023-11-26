#include <iostream>
#include <algorithm>
using namespace std;

int arr[10005] = {}; 
long sum = 0;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int temp=0, head=0;
    while (temp < n-1){
        // for (int i=0; i<n; i++){
        //     cout << arr[i] << " ";
        // }
        sort(arr+temp-1, arr+n);
        arr[temp] = arr[temp]+arr[temp+1];
        arr[temp+1] = 0;
        sum += arr[temp];
        temp++;
        // cout << endl;
    }
    cout << sum << endl;
    return 0;
}