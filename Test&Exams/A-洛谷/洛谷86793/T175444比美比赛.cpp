#include <iostream>
using namespace std;

int arr[1005];

int find(int n){
    int count = 0;
    for (int i=0; i<n; i++){
        if (arr[i] < arr[n]) count++;
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        printf("%d ", find(i));
    }
    return 0;
}