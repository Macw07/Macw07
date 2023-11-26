#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct employee{
    int id, a, b, c;
} arr[1005];

bool cmp(employee a, employee b){
    if (a.a == b.a){
        if (a.c == b.c){
            if (a.b == b.b){
                return a.b < b.b;
            }
            return a.c < b.c;
        }
        return a.c > b.c;
    }
    return a.a > b.a;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int id, a, b, c;
        cin >> id >> a >> b >> c;
        arr[i] = (employee){id, a, b, c};
    }
    sort(arr+1, arr+1+n, cmp);
    for (int i=1; i<=n; i++) cout << arr[i].id << " ";
    return 0;
}