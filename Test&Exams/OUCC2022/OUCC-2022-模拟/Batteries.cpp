// https://oucc.seedasdan.org/index.php?action=user_question&grq_id=1770 
/*
4
5,0
2,50
1,-30
6,0
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int a1[10000], a2[10000];
int l=0, r=100000000, ans;

bool check(int mid){
    int capacity = mid;
    int now_level = mid;
    for (int i=1; i<=n; i++){
        if (a2[i] == 0) now_level -= a1[i];
        if (a2[i] < 0){
            now_level = min(capacity, now_level + a2[i] / -10);
        }
        if (a2[i] > 0) now_level -= a2[i]/10 + a1[i];
        if (now_level < 0) return false;
    }
    return now_level >= 0;
}

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d,%d", &a1[i], &a2[i]);
    }
    while(l <= r){
        int mid = (l+r)>>1;
        if (check(mid)){
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}