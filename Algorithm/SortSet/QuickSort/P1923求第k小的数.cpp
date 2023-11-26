#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int arr[5000005];

// 整体思路：快速排序不一定需要把整一个都排好序，只需要排第k个数及前面的数即可
void quicksort(int l, int r){
    int i, j, pivot;
    i = l, j = r, pivot = arr[(l+r)/2];
    
    do{
        while(arr[j] > pivot) j--;
        while(arr[i] < pivot) i++;
        if (i <= j) {swap(arr[i], arr[j]); i++; j--;}
    } while(i <= j);

    // 分成三个部分
    if (k <= j) quicksort(l, j);
    else if (i <= k) quicksort(i, r);
    else{
        cout << arr[j+1] << endl;
        exit(0);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quicksort(0, n-1);
    return 0;
}