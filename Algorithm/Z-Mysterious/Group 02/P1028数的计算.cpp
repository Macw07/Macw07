#include<iostream>
using namespace std;
// int recursion(int n){
//     if(n==1){
//         return 1;
//     }
//     else if(n==2){
//         return 2;
//     }
//     else if(n%2==1){
//         return recursion(n-1);
//     }
//     return recursion(n/2)+recursion(n-1);  
// }

long long arr[1005] = {};

int main(){
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=n; i++){
        if (i % 2 == 1){
            arr[i] = arr[i-1];
        } else{
            arr[i] = arr[i/2] + arr[i-1];
        }
    }
    cout << arr[n];
    return 0;
}