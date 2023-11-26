#include <iostream>
using namespace std;

int arr[100005] = {}, n, m, temp = 0, mi = 0x7f7f7f;

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<=n-m; i++){
        for (int j=i; j<i+m; j++){
            temp += arr[j];
        }
        if (temp < mi){
            mi = temp;
        }
        temp = 0;
    }
    printf("%d", mi);
    return 0; 
}