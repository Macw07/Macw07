#include <iostream>
#include <algorithm>
using namespace std;

int n, m, now = 0;

struct node{
    int direction;
    string name;
};

node arr[100005];

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i].direction >> arr[i].name;
    }
    for (int i=1; i<=m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        // 顺时针的模拟
        if (t1 == arr[now].direction){
            if (now - t2 < 0){
                now = n + (now-t2)%n;
            } else now -= t2;
        } else{
            if (now + t2 >= n){
                now = 0 + (now + t2)%n;
            } else now += t2;
        }   
    } 
    cout << arr[now].name << endl;
    return 0;
}