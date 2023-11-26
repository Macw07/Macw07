#include <iostream>
#include <algorithm>
using namespace std;

// 逆序对 - 归并排序
int n;
long long ans = 0;
int arr[500005], temp[500005];

void Merge(int left, int mid, int right){
    int ls = left, le = mid;
    int rs = mid+1, re = right;
    int pointer = left;
    while(ls <= le && rs <= re){
        if (arr[ls] <= arr[rs]){
            temp[pointer++] = arr[ls++];
        } else{
            temp[pointer++] = arr[rs++];
            ans += le-ls+1;
        }
    }
    while(ls <= le){
        temp[pointer++] = arr[ls++];
    }
    while(rs <= re){
        temp[pointer++] = arr[rs++];
    }
    for (int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
    return;
}

void MergeSort(int left, int right){
    // 分成两个部分
    if (left < right){
        int mid = (left+right)>>1;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
    return;
}

int main(){
    scanf("%d\n", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    MergeSort(0, n-1);
    printf("%lld", ans);
    return 0;
}