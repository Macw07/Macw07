#include <iostream>
using namespace std;

int main(){
    int arr[105] = {}, i=0;
    while (true){
        cin >> arr[i];
        if (arr[i] == 0) break;
        i++;
    }
    for (int j=i-1; j>=0; j--){
        cout << arr[j] << " ";
    }
    return 0;
}