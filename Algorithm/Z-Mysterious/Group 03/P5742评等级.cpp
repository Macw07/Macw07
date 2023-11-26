#include <iostream>
using namespace std;

struct student{
    double id, s1, s2, fs;
};

student arr[10005] = {};

int main(){
    int n, s;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].id >> arr[i].s1 >> arr[i].s2;
        arr[i].fs = arr[i].s1*7 + arr[i].s2*3;
    }
    for (int i=0; i<n; i++)
        if ((arr[i].s1 + arr[i].s2 > 140) && (arr[i].fs >= 800)){
            cout << "Excellent\n";
        } else {
            cout << "Not excellent\n";
        }
    return 0;
}