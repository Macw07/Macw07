#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100005];
int temp[100005];

void Merge(int left, int mid, int right){
    int ptrl = left;  // pointer left
    int ptrr = mid + 1;  // pointer right
    int ptr = 0;
    while(ptrl <= mid && ptrr <= right){
        if (arr[ptrl] <= arr[ptrr]){
            temp[ptr++] = arr[ptrl++];
        } else{
            temp[ptr++] = arr[ptrr++];
        }
    }
    while(ptrl <= mid){
        temp[ptr++] = arr[ptrl++];
    }
    while(ptrr <= right){
        temp[ptr++] = arr[ptrr++];
    }
    // 把temp中的数字放回去
    for (int i=0; i<=right-left; i++){
        arr[left + i] = temp[i];
    }
    return ;
}

void MergeSort(int left, int right){
    // 排序的基本范围
    if (left < right){
        int mid = (left+right) >> 1;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
    return ;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);  // 归并排序中，默认索引从0开始为第一个数据。
    }
    MergeSort(0, n-1);
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}