#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    freopen("testcase010.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 5000 + 10;
    int m = rand() % 5000 + 10;
    cout << n << endl;
    int arr[100005];
    for (int i=1;i<=n; i++) arr[i] = i;
    while(m--){
        int a = rand() % n + 1;
        int b = rand() % n + 1;
        swap(arr[a], arr[b]);
    }
    for (int i=1;i<=n; i++) cout << arr[i] << " ";
    return 0;
}