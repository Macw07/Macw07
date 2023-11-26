#include <iostream>
#include <algorithm>
using namespace std;

int n;  // 站点的数量
int price[150], patrol[150];  // 分别表示第i站时，小猫吃的鱼的价格以及油费
int ans = 0;  // 答案：最少花销
int min_costs = 0x7f7f7f7f;  // 最小的花销（贪心判断）  

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> price[i] >> patrol[i];

    // 贪心：依次遍历每一个站点，如果当前站点的开销比之前的最低开销还要低，我们就购买当前站点的鱼。
    for (int i=1; i<=n; i++){
        if (price[i] < min_costs){
            min_costs = price[i];
        }
        ans += min_costs;
        min_costs += patrol[i];
    }
    cout << ans << endl;
    return 0;
}