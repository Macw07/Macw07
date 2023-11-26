/* 给定10个整数的序列，要求对其重新排序。排序要求:
1.奇数在前，偶数在后；
2.奇数按从大到小排序；
3.偶数按从小到大排序。 */

#include <iostream>
using namespace std;

int arr[10];

int main(){
    for (int i=0; i<10; i++){
        cin >> arr[i];
    }
    for (int i=0; i<10; i++){
        for (int j=0; j<10-1-i; j++){
            if (arr[j]%2==0 && arr[j+1]%2!=0){
                swap(arr[j],arr[j+1]);
            }
            if (arr[j]%2==0 && (arr[j] > arr[j+1])){
                swap(arr[j],arr[j+1]);}
            if(arr[j+1]%2==1 && arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
}