#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y;

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &x, &y);
        // 贪心原理：为了让转弯次数最少，因此选择一直走长边而不是短边。
        // 同时，每一次“掉头”需要转弯两次，每次在短边掉头。总掉头次数等于短边-1。
        // 因此直接输出答案即可。
        cout << 2*(min(x, y)-1) << endl;
    }
    return 0;
}