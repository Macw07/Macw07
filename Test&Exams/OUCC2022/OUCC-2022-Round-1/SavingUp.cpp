#include <iostream>
#include <algorithm>
using namespace std;

int arr[50];
int sum = 0;

int main(){
    for (int i=1; i<=20; i++) cin >> arr[i];
    for (int i=1; i<=20; i++){
        sum += arr[i];
        if (sum >= 1000){
            cout << i << endl;
            return 0;
        }
        sum -= 20;
    }
    return 0;
}