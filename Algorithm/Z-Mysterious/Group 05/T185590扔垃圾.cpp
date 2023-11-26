#include <iostream>
#include <algorithm>
using namespace std;

double arr[1005] = {};

int main(){
    int n, total=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    // 双指针
    int i=0, j=n-1;
    while (i <= j){
        if (arr[i] + arr[j] < 3){
            total++;
            i++;
            j--;
        } else{
            total++;
            j--;
        }
    }
    cout << total;
    return 0;
}