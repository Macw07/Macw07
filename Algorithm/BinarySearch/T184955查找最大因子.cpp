#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int l=1, r=0;
int arr[100005];

bool check(int mid){
    int sum=0;
    for (int i=0; i<n; i++){
        sum += ceil(double(arr[i])/mid);
    }
    return sum >= m;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        r += arr[i];
    }
    // cout << check(14) << endl;
    while(l+1 != r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        } else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}