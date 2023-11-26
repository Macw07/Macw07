#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main(){
    int count=0;
    for (int i=0; i<5; i++){
        int t;
        cin >> t;
        if (t==0) count++;
        arr[i] = t;;
    }
    sort(arr, arr+5);
    int pre = arr[count];
    for (int i=count; i<5-1; i++){
        int temp = count;
        bool flag=0;
        if (pre + 1 == arr[i+1]){
            // cout << "YES1" << endl;
            pre = arr[i+1];
            continue;
        }
        for (int j=1; j<count, temp>0; j++){
            // cout << pre+j << endl;
            temp--;
            if (pre + j + 1 == arr[i+1]){
                // cout << "?" << endl;
                flag = 1;
                break;
            }
        }
        if (flag){
            pre = arr[i+(count-temp)];
            count = temp;
            // cout << temp << ":" << endl;
        } else{
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
    return 0;
}