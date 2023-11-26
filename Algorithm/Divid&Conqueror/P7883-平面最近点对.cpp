#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
struct dimension{double x, y;};
dimension arr[400005];

bool cmp(dimension a, dimension b){
    return a.x < b.x;
}

double distance(int a, int b){
    dimension aa = arr[a], bb = arr[b];
    return pow(aa.x-bb.x, 2) + pow(aa.y-bb.y, 2);
}

double divconq(int left, int right){
    if (left == right){
        return 0x7f7f7f7f;
    }
    if (right-left == 1){
        return distance(left, right);
    }
    double ans = 0;
    int mid = (left+right)>>1;
    ans = min(divconq(left, mid), divconq(mid+1, right));
    int temp[10005];
    int cnt = 0;
    for (int i=left; i<=right; i++){
        if (fabs(arr[mid].x - arr[i].x) > ans) continue;
        temp[cnt++] = i;
    }
    for (int i=0; i<cnt; i++){
        for (int j=i+1; j<cnt; j++){
            ans = min(ans, distance(temp[i], temp[j]));
        }
    }
    return ans;
}   

int main(){
    scanf("%d\n", &n);
    for (int i=0; i<n; i++){
        scanf("%lf %lf", &arr[i].x, &arr[i].y);
    }
    sort(arr, arr+n, cmp);
    printf("%.0f" ,divconq(0, n-1));
    return 0;
}