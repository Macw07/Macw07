#include <iostream>
using namespace std;

int total=0, n;
int arr[1000005];

int main(){
    cin >> n;
    for (int i=1; i<=6; i++){
        cin >> arr[i];
    }
    int temp=0;  // 连续签到天数
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        if (t == 0){
            temp = 0;
            continue;
        }
        temp += 1;
        if (temp < 3){
            total += arr[1];
        } else if (temp < 7){
            total += arr[2];
        } else if (temp < 30){
            total += arr[3];
        } else if (temp < 120){
            total += arr[4];
        } else if (temp < 365){
            total += arr[5];
        } else{
            total += arr[6];
        }
    }
    cout << total << endl;
}