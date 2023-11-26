#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1005];

int recursion(int number){
    if (arr[number]) return arr[number];
    int sum = 1;
    for (int i=1; i<=number/2; i++){
        sum += recursion(i);
    }
    arr[number] = sum;
    return sum;
}

int main(){
    cin >> n;
    cout << recursion(n) << endl;
    return 0;
}