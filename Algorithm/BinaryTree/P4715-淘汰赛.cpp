#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n;
// 存放每个国家的能力值
int power[300];
//  存放是哪个国家赢了
int win[300];

void dfs(int index){
    if (index >= 1 << n) return ;
    
    dfs(index * 2);
    dfs(index * 2 + 1);
    
   
    // cout << index * 2 << " " << index * 2 + 1 << endl;
    
    if (power[index * 2] < power[index * 2 + 1]){
        win[index] = win[index * 2 + 1];
        power[index] = power[index * 2 + 1];
    } else{
        win[index] = win[index * 2];
        power[index] = power[index * 2];
    }

    // cout << power[index] << endl;
    return ;
}

int main(){
    cin >> n;
    for (int i=0; i< 1 << n; i++){
        int t;
        cin >> t;
        power[(i + (1 << n))] = t;
        win[i + (1 << n)] = i + 1;
    }
    dfs(1);  // 从第一个节点开始递归下去
    cout << (power[2] > power[3] ? win[3] : win[2]) << endl;
    return 0;
}