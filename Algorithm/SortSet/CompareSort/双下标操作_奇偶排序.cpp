#include <iostream>
#include <algorithm>
using namespace std;

int arr[10], a=0, b=9;

bool cmp(int a, int b) {return a>b;}

int main(){
    for (int i=0; i<10; i++){
        int t;
        cin >> t;
        if (t%2){
            arr[a++] = t;
        } else {
            arr[b--] = t;
        }
    }
    sort(arr+0, arr+a, cmp);
    sort(arr+b+1, arr+10);
    for (int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}