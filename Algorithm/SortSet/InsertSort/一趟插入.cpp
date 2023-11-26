// 给定一个升序序列（数字从小到大排序），现在要将一个数 x 插入到这个序列中，要求插入 x 后的新序列依然有序。
// 序列是由整数构成的，均在 int 表示的范围内。

#include <iostream>
using namespace std;

int arr[1005] = {};
int new_arr[1005] = {};

int main(){
    int times, num;
    cin >> times >> num;
    for (int i=0; i<times; i++){
        cin >> arr[i];
    }
    bool flag = true;
    int old = -1;
    int now = -1;
    for (int i=0; i<=times; i++){
        new_arr[now] = arr[old];
        // cout << new_arr[now] << endl;
        if (arr[now+1] > num && flag){
            // cout << "TRUE" << endl;
            flag = false;
            new_arr[now] = arr[old];
            new_arr[now+1] = num;
            now++;
        }
        old++;
        now++;
    }
    if (flag){
        new_arr[times] = num;
    }
    for (int i=0; i<times+1; i++){
        cout << new_arr[i] << " ";
    }
}