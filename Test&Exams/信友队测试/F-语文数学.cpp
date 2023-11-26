#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node{
    int a, b;
} arr[1005];

bool cmp(node a, node b){
    if (a.a + a.b == b.a + b.b) return a.a > b.a;
    else return a.a + a.b > b.a + b.b;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].a >> arr[i].b;
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].a << " " << arr[i].b << endl;
    }
    return 0;
}