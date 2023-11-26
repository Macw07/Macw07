#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, alphabet[30] = {};  // 每个字母的数值
int order[30], cnt;
bool vis[30];
char addendA[30], addendB[30], sum[30];

bool check(){
    // 尝试将两个n进制数字相加
    int t1, t2, added, c = 0;
    for (int i=n-1; i>=0; i--){
        t1 = alphabet[addendA[i]], t2 = alphabet[addendB[i]], added = t1 + t2 + c;
        if (added % n != alphabet[sum[i]]) return false;
        c = added / n;
    }
    return true;
}

bool canPrune(){
    if (alphabet[addendA[0]] + alphabet[addendB[0]] >= n) return true;
    // 提前判断，有问题就提前终止了。
    int t1, t2, added;
    for (int i=n-1; i>=0; i--){
        t1 = alphabet[addendA[i]], t2 = alphabet[addendB[i]], added = t1 + t2;
        if (t1 == -1 || t2 == -1 || alphabet[sum[i]] == -1) continue;
        if (added%n != alphabet[sum[i]] && (added+1)%n != alphabet[sum[i]]) return true;
    }
    return false;
}

void dfs(int index){
    if (canPrune()) return;

    if (index >= n){
        if (check()){
            for (int i=0; i<n; i++){
               printf("%d ", alphabet[i]);
            }
            exit(0);
        }
        return;
    }

    for (int i=n-1; i>=0; i--){  // 数字要从大到小循环
        if (vis[i]) continue;
        vis[i] = 1;
        alphabet[order[index]] = i;
        dfs(index + 1);
        alphabet[order[index]] = -1;
        vis[i] = 0;
    }
    return;
}

void GetNext(int k){
    if (vis[k]) return;
    vis[k] = 1;
    order[cnt++] = k;
    return ;
}

int main(){
    scanf("%d %s %s %s", &n, &addendA, &addendB, &sum);
    // 还是要修改一下顺序，按照字母从低位到高位的先后顺序来搜索。
    for (int i=n-1; i>=0; i--){
        // 常数优化
        addendA[i] -= 'A';
        addendB[i] -= 'A';
        sum[i] -= 'A';
        alphabet[i] = -1;
        // 遍历顺序优化
        GetNext(addendA[i]), GetNext(addendB[i]), GetNext(sum[i]);
    }
    memset(vis, 0, sizeof vis);
    dfs(0);
    return 0;
}