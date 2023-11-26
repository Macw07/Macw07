#include <iostream>
using namespace std;

int main(){
    /* 
    int var1;
    char var2[10];

    cout << "var1 的变量地址: " << &var1 << endl;
    cout << "var2 的变量地址: " << &var2 << endl; */
    int var = 20;
    int *ip;
    
    ip = &var; // 在指针变量中存储 var 的地址

    cout << "Value of var variable: ";
    cout << var << endl;

    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;

    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;

    return 0;

}