#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
这题写的好心烦啊！
*/

int n, lb, rb, ans;
// arr[i]: 每个人的能力值; b[i]: 一组有几个人; f[i]: 每组的最高能力值。
int arr[100005], b[100005], f[100005];
priority_queue<int, vector<int>, greater<int> > que;

void copy(){
    while(!que.empty()) que.pop();
    for (int i=0; i<n; i++) que.push(arr[i]);
};

// 尝试分组，至少以mid个人为一组
bool check(int mid){
    int position = 0, point = 0, maxi = 0x7f;
    for (int i=0; i<n; i++){
        point = -1, maxi = 0x7f7f7f7f;
        for (int j=0; j<position; j++){
            if (f[j] < maxi && b[j]+1 == arr[i]){
                point = j;  // 记录位置
                maxi = f[j];
            }
        }
        if (point == -1){  // 没有分到组
            f[position] = 1;
            b[position] = arr[i];
            position += 1;
        } else{
            b[point] = arr[i];
            f[point] += 1;
        }
    }
    for (int i=0; i<position; i++){
        if (f[i] < mid) return false;
    }
    return true;
}

bool check_died1(int mid){
    queue<int> temp;
    int cnt = 1;
    int previous = que.top(); que.pop();
    while(!que.empty()){
        int top = que.top();
        que.pop();
        // 合法的组合
        if (top - 1 == previous) {
            cnt += 1;
            previous = top;
        }
        // 非法的组合
        else if (top == previous) temp.push(top);
        else {
            if (cnt < mid) return false;
            previous = top;
            cnt = 1;
            while(temp.size()) {
                que.push(temp.front());
                temp.pop();
            }
        }
    }
    return true;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    lb = 1, rb = n;
    while(lb <= rb){
        int mid = (lb+rb) >> 1;
        if (check(mid)){
            ans = mid;
            lb = mid + 1;
        } else rb = mid - 1;
    }
    cout << ans << endl;
    return 0;
}