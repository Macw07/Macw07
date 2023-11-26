#include <iostream>
#include <algorithm>
using namespace std;

struct patient { 
    string id;
    int age;
    int queue;
};
patient arr[10005] = {};

bool temp(patient a, patient b) {
    if (a.age>=60 && b.age>=60){
        if (a.age != b.age){
            return a.age > b.age;
        }
        return a.queue < b.queue;
    }
    if (a.age>=60 && b.age<60){
        return true;
    }
    if (a.age<60 && b.age>=60){
        return false;
    }
    return a.queue < b.queue;
}

int main() {
    int n, age;
    string id;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> id >> age;
        patient p = {id, age, i};
        arr[i] = p;
    }
    sort(arr, arr+n, temp);
    for (int i=0; i<n; i++) {
        cout << arr[i].id << endl;
    }
    return 0;
}