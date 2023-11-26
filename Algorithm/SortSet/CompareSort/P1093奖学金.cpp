#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    int a;
    int b;
    int c;
    int total;
};

stu arr[500] = {};

bool cmp(stu a, stu b){
    if (a.total != b.total){
        return a.total > b.total;
    }
    if (a.total == b.total){
        if (a.a == b.a){
            return a.id < b.id;
        } else{
            return a.a > b.a;
        }
    }
    return false;
}
int main(){
    int n, a, b, c;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a >> b >> c;
        stu s = {i+1, a, b, c, a+b+c};
        arr[i] = s;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<5; i++){
        cout << arr[i].id << " " << arr[i].total << endl;
    }
    return 0;
}