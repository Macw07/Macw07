// 找找谁的身高超过全家的平均身高(整数)。全家n口人，输入输出数据如下： (平均身高保留一位小数)

#include <iostream>
using namespace std;

int arr[505];

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i=0; i<n; i++){
        sum += arr[i];
        // cout << arr[i] << endl;
    }
    float average = float(sum)/n;
    printf("AV=%.1f\n", average);
    int count = 0;
    for (int i=n-1; i>=0; i--){
        if (arr[i]>average){
            count += 1;
            cout << count << ":" << arr[i] << " ";
        } else{
            break;
        }
    }
}