/* 输入 n 个正整数，要求输出最长的连号的长度。 */

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    int max = 0;
    int temp = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++){
        if (arr[i]+1 == arr[i+1]){
            temp += 1;
        } else {
            temp = 0;
        }
        if (temp != 0 and temp > max){
            max = temp;
        }
        // cout << max << endl;
    }
    max += 1;
    cout << max;
}