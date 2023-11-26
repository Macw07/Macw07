#include <iostream>
#include <algorithm>
using namespace std;

struct employee{
    int id;
    string number;
    string depart_id;
    int tardies = 0;
};

employee arr[100] = {};

bool cmp(employee a, employee b){
    return a.id < b.id;
}

int main(){
    int n, m, a, b;
    cin >> n >> m;
    // 员工信息录入
    for (int i=0; i<n; i++){
        cin >> arr[i].id >> arr[i].number >> arr[i].depart_id;
    }
    for (int i=0; i<m; i++){
        cin >> a >> b;
        if (b > 9){
            for (int i=0; i<n; i++){
                if (arr[i].id == a){  
                    arr[i].tardies += 1;
                }
            }
        }
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        cout << arr[i].id << " " << arr[i].number << " " << arr[i].depart_id << " " << arr[i].tardies << endl;
    }
}