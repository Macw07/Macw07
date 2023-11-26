/* 明明想让大家帮他一个忙，帮他找出这么多数中是否存在一个数，
如果存在，告诉他这个数的位置，如果没有，就告诉他-1 */
#include <iostream>
using namespace std;

int main(){
    int total;
    cin >> total;
    int arr[total];
    for (int i=0; i<total; i++){
        cin >> arr[i];
    }
    int findto;
    cin >> findto;
    bool flag = 0;
    for (int i=0; i<total; i++){
        if (arr[i] == findto){
            flag = 1;
            cout << i+1;
            break;
        }
    }
    if (!flag) {
        cout << -1;
    }
    return 0;
}