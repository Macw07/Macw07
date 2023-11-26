#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans[100];

void recursion(int index){
    // 终止条件
    if (index == n){
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    // 遍历每一个元素
    for (int i=index; i<=n; i++){
        // 不断的进行交换
        swap(ans[index], ans[i]);
        recursion(index+1);
        swap(ans[index], ans[i]);
    }
    return; 
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        ans[i] = i;
    }
    recursion(1);
    return 0;
}