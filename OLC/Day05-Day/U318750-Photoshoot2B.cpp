#include <iostream>
#include <algorithm>
using namespace std;

int n, total, max_; 
int arr[100005];
int target[100005];
int tmp[100005];

/*
首先第一步需要做的事情就是将arr数组中的每一个数字与target数组中的每一个数字一一对应。
设立一个数组tmp[]，tmp[i]表示的是第i头奶牛1所拍照时最重要做的位置。
则题目要求就简化成了让tmp[i]中的所有数字按照升序的方式进行排列。

因此，在tmp数组中，如果一个数要往左移，那么这个数的左边一定有比这个数大的数。
所以问题就被转化成了在tmp[i]的左边有多少个大于tmp[i]的数字。
永远让某一头牛尽可能的多向前移动即可。
*/

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    for (int i=1; i<=n; i++) {
        scanf("%d", &target[i]);
        tmp[target[i]] = i;
    }
    for (int i=1; i<=n; i++){
        int k = tmp[arr[i]];  // k表示这头牛需要被摆放到的最终位置。
        if (k > max_) max_ = k; 
        else total += 1;
    }
    cout << total << endl;
    return 0;
}