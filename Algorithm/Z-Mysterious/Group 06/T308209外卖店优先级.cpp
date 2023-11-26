#include <iostream>
#include <algorithm>
using namespace std;

// 花了一个晚上和一个下午的时间，终于把这道题给搞定了。
// 用了两种不同的方法，第一次TLE了，真的很伤心
// 后来改头换面，从头换了个思路写。真伤心 :(

int n, m, t;  // 有n家店铺，m个订单，求再t时刻的时候有几家店在优先队列里。
int ans = 0, start = 0;
struct order{
    int self_time_stamp;
    int self_vendor;
};

order arr[1000005];
int score[1000005];
int isOrdered[1000005];
bool isPriorited[100005];

bool cmp1(order a, order b){
    return a.self_time_stamp < b.self_time_stamp;
}

bool cmp2(order a, order b){
    if (a.self_vendor != b.self_vendor) return  a.self_vendor < b.self_vendor;
    return a.self_time_stamp < b.self_time_stamp;
}

void method1(){
    // 数据读入
    scanf("%d %d %d", &n, &m, &t);
    for (int i=0; i<m; i++){
        scanf("%d %d", &arr[i].self_time_stamp, &arr[i].self_vendor);
    }

    // 给m条订单排序，时间越早的订单排的越前。
    sort(arr, arr+m, cmp1);

    for (int i=1; i<=t; i++){
        // 枚举每一个时间为i的订单
        for (int j=start; j<m; j++){
            if (arr[j].self_time_stamp == i){
                isOrdered[arr[j].self_vendor]++;
            }
            else{
                start = j;
                break;
            }
        }
        // 枚举每一个店家
        for (int j=1; j<=n; j++){
            if (isOrdered[j] >= 1){
                score[j] += 2*isOrdered[j];
                // printf("%d时刻时, %d店铺收到了%d个订单\n", i, j, isOrdered[j]);
                if (score[j] > 5 && !isPriorited[j]) {isPriorited[j] = true; ans++;}
            } else{
                score[j] = max(0, score[j]-1);
                // printf("%d时刻时, %d店铺收到了%d个订单\n", i, j, isOrdered[j]);
                if (score[j] <= 3 && isPriorited[j]) {isPriorited[j] = false; ans--;}
            }
            // 将isOrdered清除为0
            isOrdered[j] = 0;
        }
    }

    printf("%d\n", ans);
    return;
}

void method2(){
    // 数据读入
    scanf("%d %d %d", &n, &m, &t);
    for (int i=0; i<m; i++){
        scanf("%d %d", &arr[i].self_time_stamp, &arr[i].self_vendor);
    }

    sort(arr, arr+m, cmp2);

    // 遍历店家
    for (int i=1; i<=n; i++){
        // 从start开始道结束都是同一个店家的所有订单
        // cout << "我们研究了第" << i << "号店" << endl;
        int current_time = 1;
        bool isPriority = false;
        for (int j=start; j<m; j++){
            if (arr[j].self_vendor != i) {
                start = j;
                // 检查上一份订单的时间
                if (arr[j-1].self_time_stamp != t){
                    score[i] = max(0, score[i]-(t-arr[j-1].self_time_stamp));
                    if (score[i] <= 3) isPriority = false;
                }
                break;
            }
            if (arr[j].self_time_stamp == current_time){
                // 有一个订单了，可以增加2分
                // printf("%d时刻时, %d号店有一份订单\n", current_time, i);
                score[i] += 2;
                if (score[i] > 5) isPriority = true;
            } else {
                // 要到下一个订单去了
                if (arr[j].self_time_stamp == current_time + 1){
                    j--;
                    current_time++; 
                }
                else {
                    // 证明没有订单，需要扣除分数
                    score[i] = max(0, score[i]-(arr[j].self_time_stamp-current_time-1));
                    if (score[i] <= 3) isPriority = false;
                    current_time = arr[j].self_time_stamp;
                    j--;
                }
            }
        }
        // cout << score[i] << endl;
        if (isPriority) ans++;
    }
    printf("%d\n", ans);
    return;
}

int main(){
    method2();
    return 0;
}