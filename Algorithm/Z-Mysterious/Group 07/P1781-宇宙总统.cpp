#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node{
    string content;
    int id;
};
node arr[50];
int machine[25][10005];  // 表示机器i在第j个时间点是有空的
bool cmp(node a, node b){
    if (a.content.size() > b.content.size()) return true;
    if (a.content.size() == b.content.size() && a.content > b.content) return true;
    return false;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].content;
        arr[i].id = i+1;
    }
    sort(arr, arr+n, cmp);
    cout << arr[0].id << endl << arr[0].content;
    return 0;
}