#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    string name;
    int a, b, c, total;
};

student arr[105];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
        arr[i].total = arr[i].a + arr[i].b + arr[i].c;
        printf("%s %d %d %d %d\n", arr[i].name.c_str(), arr[i].a, arr[i].b, arr[i].c, arr[i].total);
    }
    return 0;
}