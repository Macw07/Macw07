#include <iostream>
#include <algorithm>
using namespace std;

int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
int temp[100];

void Merge(int left, int mid, int right){
    int lstart = left, lend = mid;
    int rstart = mid+1, rend = right;
    int pointer = left;

    while(lstart <= lend && rstart <= rend){
        // Put them in Order
        if (arr[lstart] < arr[rstart]){
            temp[pointer++] = arr[lstart];
            lstart++;
        } else{
            temp[pointer++] = arr[rstart];
            rstart++;
        }
    }   
    while(lstart <= lend){
        temp[pointer++] = arr[lstart];
        lstart++;
    }
    while(rstart <= rend){
        temp[pointer++] = arr[rstart];
        rstart++;
    }

    for (int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
    return;
}

void MergeSort(int left, int right){
    if (left < right){
        int mid = (left+right)>>1;
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
    return;
}

int main(){
    MergeSort(0, 9-1);  // 这里记得要减一个一
    for (int i=0; i<9; i++){
        cout << arr[i] << " ";
    }
    return 0;
}