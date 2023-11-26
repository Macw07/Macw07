#include <iostream>
#include <algorithm>
using namespace std;

int a1[100005];
int b1[100005];

int main(){
    int a, b;
    cin >> a >> b;
    for (int i=0; i<a; i++){
        cin >> a1[i];
    }
    for (int i=0; i<b; i++){
        cin >> b1[i];
    }
    sort(b1, b1+b);
    // 二分查找 + 遍历
    // 遍历数组中的每一个数
    for (int i=0; i<a; i++){
        // 往数组a1中查找
        int l=-1, r=b;
        // cout << b1[i] << " ";
        while(l+1 != r){
            int m = (l+r)/2;
            if (b1[m] < a1[i]){
                l = m;
            } else{
                r = m;
            }
        }
        // cout << l << " " << r << endl;
        if (b1[r] == a1[i]) cout << a1[i] << " ";
    }
    return 0;
}