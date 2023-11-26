#include <iostream>
#include <algorithm>
using namespace std;

// 可以用哈西表优化，这里我就不用map优化了。
// correspond记录每一个奶牛的名字。
string correspond[10] = {"", "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
int n;  // 如题意。
int map[10][10];  // map[i][j] == 1 表示编号为i的奶牛必须要在编号为j的奶牛后面。
string arr[10];  // 全排列，用于记录全排列的结果。
int vis[10];  // 判断这头奶牛是否被放置了。
int hasRequire[10];  // hasRequire[i]表示这头奶牛的放置有要求。

// 在correspond数组中找这头奶牛所在的位置。
int find(string name){
    for (int i=1; i<=8; i++){
        if (correspond[i] == name){
            return i;
        }
    }
    return 0;
}

// 检查是否所有的奶牛都满足了防指要求。
bool check(){
    for (int i=1; i<=8; i++){
        if (hasRequire[i]) return false;
    }
    return true;
}

void dfs(int depth){
    if (depth > 8){
        if (!check()) return ;
        // 输出结果，判断答案输出结果。
        for (int i=1; i<=8; i++) cout << arr[i] << endl;
        exit(0);  // 退出程序。
    }
    // 全排列代码。
    for (int i=1; i<=8; i++){
        if (vis[i]) continue;
        int last = find(arr[depth-1]);
        /*******************************
        这里分两种情况讨论：
        1. 这头奶牛没有放置要求，那就随便放。（else语句）
        2. 这头奶牛有放置要求，则过滤不符合要求的放置。
        *******************************/
        if (hasRequire[last]){  // 情况一。
            // map[last][i]表示上一个奶牛是否和这头奶牛有放置关系。
            if (map[last][i] == 0) continue; 
            hasRequire[last]--; hasRequire[i]--;
            vis[i] = 1;
            arr[depth] = correspond[i];
            dfs(depth + 1);
            vis[i] = 0;
            hasRequire[i]++; hasRequire[last]++;
        } else{  // 情况二。
            vis[i] = 1;
            arr[depth] = correspond[i];
            dfs(depth + 1);
            vis[i] = 0;
        }
    }
    return ;
}

int main(){
    cin >> n;

    // 初始化操作：
    // 表示第一个位置的奶牛可以随便放，没有什么特殊限制。
    for (int i=1; i<=8; i++) map[0][i] = 1;  
    // 由于程序要按照字典序最小的答案输出，先排列。
    sort(correspond+1, correspond+9);

    for (int i=1; i<=n; i++){
        string a, b, c, d, e, f;  // bcde都是没用的，直接抛弃。
        cin >> a >> b >> c >> d >> e >> f;
        int find_a = find(a);
        int find_b = find(f);
        hasRequire[find_a] += 1;
        hasRequire[find_b] += 1;
        map[find_a][find_b] = map[find_b][find_a] = 1;
    }
    
    dfs(1);  // 暴力搜索操作。
    return 0;
}