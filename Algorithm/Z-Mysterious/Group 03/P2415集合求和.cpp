#include <iostream>
#include <cmath>
using namespace std;

long long arr[100];
int i=0;
long long sum=0;

int main(){
    while(cin >> arr[i++]);
    for (int j=0; j<i; j++){
        sum += arr[j];
    }
    sum = sum * pow(2, i-2);
    cout << sum;
    return 0;
}