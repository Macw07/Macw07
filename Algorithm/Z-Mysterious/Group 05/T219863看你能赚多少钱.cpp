#include <iostream>
#include <algorithm>
using namespace std;

struct items{
    int time, value;
};
items arr[1005] = {};
bool vis[1005] = {};

bool cmp(items a, items b){
    return a.value > b.value; 
}

int main(){
    int m, n;;
    cin >> m >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].time;
    }
    for (int i=0; i<n; i++){
        cin >> arr[i].value;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        bool flag = 1;
        for(int j=arr[i].time; j>=1; j--){
            if (vis[j] == 0){
                flag = 0;
                vis[j] = 1;
                break;
            }
        }
        if(flag) m -= arr[i].value;
    }
    cout << m;
    return 0;
}