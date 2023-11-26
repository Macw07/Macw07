#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    string name;
    int id, a, b, c, total;
};

student arr[10005] = {};

bool cmp(student a, student b){
    if (a.total != b.total){
        return a.total > b.total;
    } else{
        return a.id < b.id;
    }
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].total = arr[i].a + arr[i].b + arr[i].c;
        arr[i].id = i;
    }
    sort(arr, arr+n, cmp);
    cout << arr[0].name << " " << arr[0].a << " " << arr[0].b << " " << arr[0].c;
    return 0;
}