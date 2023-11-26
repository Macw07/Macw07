/*******************************
Editorial Code - By Marco Wang
Name: Macw的杭州旅行
Tags: Dichotomous Search for Results.
*******************************/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
/*
这道题是一道贪心+二分题目。
用二分算法解决局部最优解，并通过局部最优解组成最终答案。
并且，每一个局部的最优解具有单调性，即如果可以购买k份鱼饲料，则一定可以购买k-1份鱼饲料。
若购买k份鱼饲料后体力不足，则购买k+1份鱼饲料后体力肯定也不足。
*/

ll total = 0;  // 用于记录每一个测试点的答案。
ll pointer = 1;  // pointer表示正在处理第pointer个垂钓者。
ll t, l, n, m, k;  // 根据题目变量命名，请参照题目。
ll station[1000005];  // station[i]表示第i个小卖部。
ll customer[1000005];  // customer[i]表示第i个垂钓者。
bool flag = false;  // 判断答案是否合法（是否有答案）。

// check函数用于判断当携带mid个水时，是否可以满足体力要求。
bool check(ll mid, ll dbegin, ll dend, ll begin){
    ll temp = k;  // temp指的是Macw和他的朋友们的当前体力值。
    // 模拟Macw和他的朋友们每走一个单位距离所消耗的能量。
    for (ll i=dbegin; mid && i<dend; i++){
        while (mid && customer[begin] == i){
            begin += 1;
            mid -= 1;
            flag = true;
        }
        temp -= mid;
    }
    // 如果体力值小于0，则会被市场监督管理局抓到。
    return temp >= 0;
}

int main(){
    // freopen("Data/Q30.in", "r", stdin);
    // freopen("Data/Q30.out", "w", stdout);
    cin >> t;  // 输入多组数据。
    while(t--){
        // 初始化程序。
        flag = false; 
        total = 0, pointer = 1;

        scanf("%lld %lld %lld %lld", &l, &n, &m, &k);
        for (int i=1; i<=n; i++) scanf("%lld", &station[i]);
        station[++n] = l; 
        for (int i=1; i<=m; i++) scanf("%lld", &customer[i]);

        // 记得要按照坐标排序，垂钓者的坐标不一是按照顺序给定的。
        sort(station+1, station+n+1);
        sort(customer+1, customer+m+1);
        station[n+1] = 0x7f7f7f7f;

        // 贪心：去判断在每一个小卖部最多可以买几份鱼饲料。
        for (ll i=1; i<n; i++){
            // 判断每一个是从哪一个顾客区间开始进行二分。
            for (ll j=pointer; j<=m; j++){
                if (customer[j] <= station[i]) pointer++;
                else break;
            }
            if (pointer > m) break;
            ll k = 0;  // 记录最后可以售卖的数量。
            for (ll j=pointer; j<=m; j++){
                if (customer[j] < station[i+1]) k++;
                else break;
            }
            // 二分进行判断，找出最优的解。
            ll left=0, right=k, ans = 0;
            flag = false;
            while (left <= right){
                ll mid = (left+right) >> 1;
                if (check(mid, station[i], station[i+1], pointer)){
                    left = mid + 1;
                    ans = mid;
                } else right = mid - 1;
            }
            if (flag) {
                total += ans;
            }
        }
        // 输出结果。
        printf("%lld\n", total);
    }
    return 0;
}