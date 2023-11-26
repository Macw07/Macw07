#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {return a+b > b+a;}
string arr[25];
int n;

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++) cout << arr[i];
    return 0;
}