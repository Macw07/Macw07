#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
int arr[25] = {0, 1};
int visited[25];

bool isPrime(int k){
    if (k == 1) return true;
    for (int i=2; i<=sqrt(k); i++){
        if (k % i == 0) return false;
    }
    return true;
}

void permutation(int index){
    if (index > n){
        if (isPrime(1+arr[n])){
            for (int i=1; i<=n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i=2; i<=n; i++){
        if (visited[i] == 0 && isPrime(arr[index-1]+i)){
            visited[i] = 1;
            arr[index] = i;
            permutation(index+1);
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    cin >> n;
    permutation(2);
    return 0;
}