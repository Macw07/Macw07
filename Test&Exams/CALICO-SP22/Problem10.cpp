#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 不太清楚暴力是否过得去，试一下先。

int t, n;
string place;
struct cab{
    int origin;
    int price;
    string name;
} arr[1000005];
int vis[1000005];
struct ans{
    int begin;
    int end;
    string name;
} ans[1000005];

int main(){
    cin >> t;
    while(t--){
        cin >> place >> n;
        for (int i=1; i<=n; i++){
            vis[i] = 0;
            ans[i].begin = ans[i].end = 0;
        }
        for (int i=1; i<=n; i++) 
            cin >> arr[i].name >> arr[i].origin >> arr[i].price;
        
        int cnt = 0, times = 0;
        int last_car = 0, k = 1000000;

        while(cnt < n && k--){
            long long minimum = 0x7f7f7f7f7f7f, index = -1, end = -1;
            
            // 找到在同一个时间下价格最低的那辆车。
            for (int i=1; i<=n; i++){
                if (vis[i]) continue;
                long long price = arr[i].origin + times * arr[i].price;
                if (price < minimum){
                    minimum = price;
                    index = i;
                }
                if (price == minimum && i != last_car) index = i;
            }

            // 判断这个时间段最低的车是否跟上个时间段一样，如果一样的话就延续。
            if (index != last_car){
                ans[cnt].end = times - 1;
                cnt += 1;
                vis[last_car] = 1;
                last_car = index;
                ans[cnt].name = arr[index].name;
                ans[cnt].begin = times;

                // 是否存在最优解
                if (cnt + 1 != n){
                    end = arr[index].origin + 1000000 * arr[index].price;
                    bool flag = true;
                    for (int i=1; i<=n; i++){
                        if (vis[i] || i == index) continue;
                        long long price = arr[i].origin + 1000000 * arr[i].price;
                        if (price <= end) {
                            flag = false;
                            break;
                        }
                    }
                    // 说明已经没有最优解了，直接结束程序。
                    if (flag) break;
                }
            }

            times += 1;
        }

        printf("%s:\n", place.c_str());
        for (int i=1; i<cnt; i++){
            if (ans[i].begin == ans[i].end) printf("%d: %s\n", ans[i].begin, ans[i].name.c_str());
            else printf("%d-%d: %s\n", ans[i].begin, ans[i].end, ans[i].name.c_str());
        }
        printf("%d+: %s\n\n", ans[cnt].begin, ans[cnt].name.c_str());
    }
    return 0;
}