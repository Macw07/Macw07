/* 拼盘是指用两种以上的零食摆在同一个菜盘里合成的菜，
那现在有n种零食拼盘，零食之王想删除掉其中不想要的零食，请你帮他用编程实现
*/

#include <iostream>
using namespace std;

int arr[100] = {};

int main(){
    int kinds, remove;
    cin >> kinds >> remove;
    for (int i=0; i<kinds; i++){
        cin >> arr[i];
    }
    for (int i=0; i<kinds; i++){
        if (arr[i] != remove){
            cout << arr[i] << " ";
        }
    }
}