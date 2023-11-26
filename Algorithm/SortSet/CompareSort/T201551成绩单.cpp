#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    string id;
    int Chinese;
    int Math;
    int English;
    int total;
};
stu arr[10005] = {};

int temp(stu a, stu b){
    return a.id < b.id;
}

int main(){
    int n, t1, t2, t3;
    string id;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> id >> t1 >> t2 >> t3;
        struct stu s = {id, t1, t2, t3, t1+t2+t3};
        arr[i] = s;
    }
    sort(arr, arr+n, temp);
    for (int i=0; i<n; i++){
        cout << arr[i].id << " " << arr[i].Chinese << " " << arr[i].Math << " " << arr[i].English << " " << arr[i].total << endl;
    }
}
