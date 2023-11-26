#include <iostream>
#include <algorithm>
using namespace std;

double arr[1005];

bool cmp(double a, double b){
    return a > b;
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int n;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n, cmp);
        int now = 0;
        int total = 0;
        for (int i=0; i<n; i++){
            now += 2*arr[i];
            total++;
            if (now > 20){
                cout << total << endl;
                break;
            }
        }
    }
    return 0;
}