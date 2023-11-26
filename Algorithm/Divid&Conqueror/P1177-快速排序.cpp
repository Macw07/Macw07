#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];

void quicksort(int l, int r){
    int i=l, j=r;
    int mid = arr[(l+r)/2];
    do{
        while(arr[i]<mid) i++;
        while(arr[j]>mid) j--;
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }   
    } while(i <= j);  // 直到i和j重合
    // 继续递归
    if (l < j) quicksort(l, j);
    if (i < r) quicksort(i, r);    
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    quicksort(0, n-1);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}