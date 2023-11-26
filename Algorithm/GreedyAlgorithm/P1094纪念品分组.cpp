#include <iostream>
#include <algorithm>
using namespace std;

int arr[40005] = {};

int main(){
    int m, n, count=0;
    cin >> m >> n;
    int i=0, j=n-1;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    // for (int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    while (i <= j){
        if (i == j){
            count++;
            break;       
        }
        if (arr[i]+arr[j] > m){
            // printf("@%d %d\n", arr[i], arr[j]);
            count++;
            j--;
            continue;
        }
        else{
            // printf("%d %d\n", arr[i], arr[j]);
            count++;
            j--;
            i++;
        }
    }
    cout << count;
    return 0;
}