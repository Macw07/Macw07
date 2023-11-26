#include <iostream>
#include <algorithm>
using namespace std;

// 一道典型的贪心题目
int total = 0;
int pointer = 1;
int l, n, m, k;
int station[105];
int customer[105];
bool flag = false;

bool check(int mid, int dbegin, int dend, int begin){
    int temp = k;
    // cout << mid << endl;
    for (int i=dbegin; mid && i<dend; i++){
        while (mid && customer[begin] == i){
            begin += 1;
            mid -= 1;
            flag = true;
            // cout << "给出一瓶水 -> " << i << endl;
        }
        // cout << "过去了一个单位时间" << endl;
        temp -= mid;
    }
    // cout << temp << endl << endl;
    return temp >= 0;
}

int main(){
    cin >> l >> n >> m >> k;
    for (int i=1; i<=n; i++) cin >> station[i];
    station[++n] = l;
    for (int i=1; i<=m; i++) cin >> customer[i];
    // 记得要排序，小朋友的数据不一是按照顺序给定的
    sort(station+1, station+n+1);
    sort(customer+1, customer+m+1);
    // 贪心：去判断这个驿站最多可以买几瓶水。
    for (int i=1; i<n; i++){
        for (int j=pointer; j<=m; j++){
            if (customer[j] <= station[i]) pointer++;
            else break;
        }

        // 二分进行判断
        int left=0, right=m, ans = 0;
        flag = false;
        while (left <= right){
            int mid = (left+right) >> 1;
            if (check(mid, station[i], station[i+1], pointer)){
                left = mid + 1;
                ans = mid;
            } else right = mid - 1;
        }
        if (flag) total += ans;
    }

    cout << total << endl;
    return 0;
}