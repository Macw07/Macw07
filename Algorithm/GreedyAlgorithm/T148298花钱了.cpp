#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return b > a;
}

int main(){
    int n, t=0, count=0;
    cin >> n;
    int arr[7] = {};
    int money[7] = {1, 2, 5, 10, 20, 50, 100};
    for (int i=0; i<7; i++){
        cin >> arr[i];
    }
    for (int i=6; i>=0; i--){
        for (int j=0; j<arr[i]; j++){
            if (t+money[i] > n){
                break;
            }
            t += money[i];
            // cout << money[i];
            count++;
            if (t >= n){
                cout << count;
                return 0;
            }
        }
    }
    return 0;
}