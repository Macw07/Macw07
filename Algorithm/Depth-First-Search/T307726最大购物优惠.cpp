#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int w, v, n;
int dp[105][105][105];
int weight[105], volume[105], value[105];
int result[105];
vector<int> ans;
vector<int> finala;
int last = 0;

void p1(){
    for (int i=1; i<=n; i++){  // 遍历一遍物品
        for (int j=0; j<=w; j++){  // 遍历一遍重量
            for (int k=0; k<=v; k++){  // 遍历一遍价格
                // 如果令得起，装得下
                if (j >= weight[i] && k >= volume[i]){
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-weight[i]][k-volume[i]]+value[i]);
                } else{
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    cout << dp[n][w][v] << endl;
    int j=w, k=v, a = 0;
    // 倒着推一遍，找出路径
    for (int i=n; i>=1; i--){
        if (j >= weight[i] && k >= volume[i] && dp[i][j][k] == dp[i-1][j-weight[i]][k-volume[i]]+value[i]){
            result[a++] = i;
            j -= weight[i];
            k -= volume[i];
        }
    }
    sort(result, result+a);
    for(int i=0; i < a; i++){
		cout << result[i] << " ";
	}
    return;
}

int p2(int index, int left_weight, int left_volume){
    // 01背包的两个选择：拿和不拿
    // 如果尝试到了最后一个
    if (dp[index][left_weight][left_volume] != -1) return dp[index][left_weight][left_volume];

    if (index > n){
        // 计算最大价值
        int total = 0;
        for (int i=0; i<ans.size(); i++){
            total += value[ans[i]];
        }
        if (total >= last) {
            last = total;
            finala = ans;
        }
        return 0;
    }

    // 不拿第i个物品
    int possibility1 = p2(index+1, left_weight, left_volume);
    // 拿第i个物品
    
    // 如果可以拿
    int possibility2 = 0;
    if (left_weight-weight[index] >= 0 && left_volume-volume[index] >= 0){
        ans.push_back(index);
        possibility2 = p2(index+1, left_weight-weight[index], left_volume-volume[index]) + value[index];
        ans.pop_back();
    }

    // 二选一
    return  max(possibility1, possibility2);
}

int main(){
    cin >> w >> v >> n;
    for (int i=1; i<=n; i++){
        cin >> weight[i] >> volume[i] >> value[i];
    }
    p1();
    return 0;
}