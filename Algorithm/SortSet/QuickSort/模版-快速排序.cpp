#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int n;

void quicksort(int left, int right){
    int i, j, pivot;
    i = left, j = right, pivot = arr[(left+right)/2];

    do {
        while(arr[j] > pivot) j--;
        while(arr[i] < pivot) i++;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    
    if (left < j) quicksort(left, j);
    if (i < right) quicksort(i, right);
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    quicksort(0, n-1);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}