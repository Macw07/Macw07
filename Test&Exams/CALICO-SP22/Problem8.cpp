#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

// 说实话，这道题还是很难的。
// CALICO的难点我感觉着重在于数据量大。
// 但这道题应该不怎么需要优化就能过，我先尝试使用一下普通的算法。

int t, n, k;
char c;

int main(){
    scanf("%d", &t);
    while(t--){
        set<int> s;
        scanf("%d", &n);
        int maximum = -2147483647;
        
        for (int i=1; i<=n; i++){
            cin >> c >> k;
            if (c == 'P')  s.insert(k);
            else s.erase(k);
            if (s.size()) maximum = max(maximum, abs(*s.rbegin()-*s.begin()));
        }

        cout << maximum << endl;
    }
    return 0;
}