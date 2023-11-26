#include <iostream>
#include <algorithm>
using namespace std;

struct stu{
    string name;
    int a;
    int b;
    int c;
    int d;
    int total;
};

bool cmp(stu a, stu b){
    return a.total > b.total;
}
stu arr[1005] = {};

int main(){
    int n, a, b, c, d;
    string name;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> name >> a >> b >> c >> d;
        stu s = {name, a, b, c, d, a+b+c+d};
        arr[i] = s;
    }
    sort(arr, arr+n, cmp);
    cout << arr[0].name;
    return 0; 
}