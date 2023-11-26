#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    string name;
    int atk;
    int pri;
};

bool cmp(student a, student b){
    if (a.atk == b.atk){
        return a.pri < b.pri;
    }
    return a.atk > b.atk;
}
student arr[1005] = {};

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].atk >> arr[i].pri;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<k; i++){
        cout << arr[i].name << endl;
    }
    return 0; 
}