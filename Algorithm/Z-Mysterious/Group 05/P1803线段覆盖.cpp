#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int begin;
    int end;
};

node arr[100005];

bool cmp(node a, node b){
   return a.end < b.end; 
}

int main(){
    int n, total = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].begin >> arr[i].end;
    }
    sort(arr, arr+n, cmp);
    // 选择结束时间最早的
    int previous = -1;
    for (int i=0; i<n; i++){
        if (arr[i].begin >= previous){
            previous = arr[i].end;
            total++;
        }
    }
    cout << total << endl;
    return 0;
}