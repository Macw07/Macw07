#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[1005];
    for (int i=1; i<=1000; i++) arr[i] = i;
    for (int i=1; i<=1000; i++) cout << arr[i] << " ";
    return 0;
}