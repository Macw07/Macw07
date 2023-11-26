#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];
double sum = 0;

int main(){
    for (int i=1; i<=12; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cout << int(sum * 0.0024) << endl;
    return 0;
}