#include <iostream>
using namespace std;

/*
给定一个整型数组arr，代表数值不同的纸牌排成一条线
玩家A和玩家B依次拿走每张纸牌
規定玩家A先拿，玩家B后拿
但是每个玩家每次只能拿走最左或最右的纸牌
玩家A和玩家B都绝顶聪明
请返回最后获胜者的分数。
*/

// Memo：趁寒假时间，超越自己。最近几天在学习动态规划，动态规划是算法领域中比较难的一个玩意，
// 需要认真学，需要花费很多的时间和精力。加油！

int way1(int *arr, int len);
int f1(int *arr, int L, int R);
int g1(int *arr, int L, int R);

int way2(int *arr, int len);
int f2(int *arr, int L, int R);
int g2(int *arr, int L, int R);
int fmap1[1000][100];
int gmap1[1000][100];

int way3(int *arr, int len);
int fmap2[1000][100];
int gmap2[1000][100];

// 5 6 7 3 2 1 4 5 9 2 8
int main(){
    int arr[] = {5, 6, 7, 3, 2, 1, 4, 5, 9, 2, 8};
    cout << way1(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    cout << way2(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    cout << way3(arr, sizeof(arr)/sizeof(arr[0])) << endl;
    return 0;
}

// 方法一
int way1(int *arr, int len){
    len -= 1;
    int p1 = f1(arr, 0, len);
    int p2 = g1(arr, 0, len);
    return max(p1, p2);
}

// f1是先手
int f1(int *arr, int L, int R){
    // 如果L和R相等，这说明只有一个纸牌了，先手就直接把这个纸牌拿走即可
    if (L==R) return arr[L];
    // 如果L和R不想等，先手一定会挑选最优结果。分别判断两个最后结果的最大值。
    int p1 = arr[L] + g1(arr, L+1, R);  // 挑选了L这张牌，后手在之后的牌里挑选
    int p2 = arr[R] + g1(arr, L, R-1);  // 挑选了R这张牌，后手在L R-1的范围内挑选
    return max(p1, p2);  // 在这两个结果中取最大值返回
}

// g1是后手
int g1(int *arr, int L, int R){
    if (L==R) return 0;  // 虽然L等于R，但是由于是后手，这张牌这张牌会被先手拿走，因此没有牌可以拿了。
    int p1 = f1(arr, L+1, R);
    int p2 = f1(arr, L, R-1);
    return min(p1, p2);  // 因为最好的结果已经被先手拿了，因此只能选择较小的那一个。
}

// 方法二 - 记忆化存储
int way2(int *arr, int len){
    len -= 1;
    for (int i=0; i<=len; i++){
        for (int j=0; j<=len; j++){
            fmap1[i][j] = -1;
            gmap1[i][j] = -1;
        }
    }
    int p1 = f2(arr, 0, len);
    int p2 = g2(arr, 0, len);
    return max(p1, p2);
}

int f2(int *arr, int L, int R){
    if (fmap1[L][R] != -1) return fmap1[L][R];
    int ans = 0;
    if (L==R){
        ans = arr[L];
    } else{
        int p1 = arr[L] + g2(arr, L+1, R); 
        int p2 = arr[R] + g2(arr, L, R-1); 
        ans = max(p1, p2);
    }
    fmap1[L][R] = ans;
    return ans;  
}

int g2(int *arr, int L, int R){
    if (gmap1[L][R] != -1) return gmap1[L][R];
    int ans = 0;
    if (L!=R){
        int p1 = f2(arr, L+1, R);
        int p2 = f2(arr, L, R-1);
        ans = min(p1, p2);
    }
    gmap1[L][R] = ans;
    return ans;  
}

// 方法三 - 正经动态规划
int way3(int *arr, int len){
    for (int i=0; i<len; i++){
        fmap2[i][i] = arr[i];
    }
    for (int i=1; i<len; i++){
        int L = 0;
        int R = i;
        while(R < len){
            fmap2[L][R] = max(arr[L]+gmap2[L+1][R], arr[R]+gmap2[L][R-1]);
            gmap2[L][R] = min(fmap2[L+1][R], fmap2[L][R-1]);
            L++;
            R++;
        }
    }
    return max(fmap2[0][len-1], gmap2[0][len-1]);
}
