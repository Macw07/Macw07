/* 老师最近在编一个操作系统，正好编到鼠标的繁忙状态，
需要一个沙漏符号，正好大家都在学c++，
你的任务就是帮老师编一个程序打印一个沙漏符号。 */
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<=n/2; i++){
        for (int j=0; j<i; j++){
            cout << " ";
        }
        for (int k=0; k<n-i*2; k++){
            cout << "*";
        }
        cout << endl;
    }
    for (int i=3; i<=n; i+=2){
        for (int j=(n-i)/2; j>0; j--){
            cout << " ";
        }
        for (int j=i; j>0; j--){
            cout << "*";
        }
        cout << endl;
    }
}