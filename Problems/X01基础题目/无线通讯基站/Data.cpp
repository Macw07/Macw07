#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    freopen("testcase010.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 90 + 10;
    int arr[505];
    cout << n << endl;
    for (int i=1; i<=n; i++){
        int k = rand() % n + 1;
        arr[i] = k;
    }
    sort(arr+1, arr+1+n);
    for (int i=1; i<=n; i++) cout << arr[i] << " ";
    return 0;
}