#include <iostream>
#include <algorithm>
using namespace std;

int arr[15];
int main(){
    int n, m;
    double temp, total_heighest=0;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        temp = 0;
        for (int j=0; j<m; j++){
            cin >> arr[j];
        }
        sort(arr, arr+m);
        for (int j=1; j<m-1; j++){
            temp += arr[j];
        }
        total_heighest = max(total_heighest, temp/(m-2));
    }
    printf("%.2f\n", total_heighest);
    return 0;
}