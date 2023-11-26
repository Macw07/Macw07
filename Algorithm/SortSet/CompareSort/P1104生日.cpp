#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    string name;
    int year;
    int month;
    int day;
};
stu arr[1000] = {};

bool cmp(stu a, stu b){
    if (a.year < b.year){
        return true;
    }
    if (a.year == b.year){
        if (a.month == b.month){
            if (a.day == b.day) return a.id > b.id;
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return false;
}

int main(){
    int n, a, b, c;
    string name;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> name >> a >> b >> c;
        stu s = {i, name, a, b, c};
        arr[i] = s;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].name << endl;
    }
    return 0;
}