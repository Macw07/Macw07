#include <iostream>
using namespace std;

int main(){
    // freopen("testcase010.in", "r", stdin);
    // freopen("testcase010.out", "w", stdout);
    int arr[55] = {};
    int warning[55] = {}, a=0;
    int written[55] = {}, b=0;
    int n, m, t;
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> t;
        if (t > n){
            warning[++a] = i;
        }
        if (t > n * 1.2){
            written[++b] = i;
        }
    }
    if (a == 0){
        cout << "SO SAD" << endl;
    }else{
        for (int i=1; i<=a; i++) cout << warning[i] << " ";
        cout << endl;
        for (int i=1; i<=b; i++) cout << written[i] << " ";
        cout << endl;
    }
    return 0;
}