/* 使用1角、2角、5角硬币组成 n 角钱。设1角、2角、5角的硬币各用了a、b、c个，列出所有可能的a, b, c组合。
输出顺序为：先按c的值从小到大，若c相同则按b的值从小到大。*/

#include <iostream>
using namespace std;

int main(){
    int target;
    cin >> target;
    int count = 1;
    for (int i=0; i<=target/5; i++){
        for (int j=0; j<=target/2; j++){
            for (int k=0; k<=target; k++){
                if (i*5 + j*2 + k == target){
                    cout << count << ":" << k << " " << j << " " << i << endl;
                    count ++;
                }
            }
        }
    }
}