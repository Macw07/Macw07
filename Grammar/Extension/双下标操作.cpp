// 双下标操作
#include <iostream>
using namespace std;

int arr[6] = {1, 2, 3, 4, 5, 6};

int main(){
    int i=0, j=6-1;
    while (i<j){
        cout << arr[i]+arr[j] << " ";
        i++, j--;
    }
    return 0;
}