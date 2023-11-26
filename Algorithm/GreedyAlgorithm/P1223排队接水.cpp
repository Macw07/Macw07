#include <iostream>
#include <algorithm>
using namespace std;

struct patient{
    int id, t;
};

patient arr[1005] = {};
int waitt[1005] = {};

bool cmp(patient a, patient b){
    return a.t < b.t;
}

int main(){
    int n, t;
    long long total=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        patient p = {i+1, t};
        arr[i] = p;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].id << " ";
    }
    cout << endl;
    waitt[0] = arr[0].t;
    total += waitt[0];
    for (int i=1; i<n-1; i++){
        waitt[i] = waitt[i-1]+arr[i].t;
        total += waitt[i];
    }
    printf("%.2f", double(total)/n);
    return 0;
}