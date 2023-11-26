#include <iostream>
#include <string>
using namespace std; 

int main(){
    int i,j;
    std::cout << "请输入第一个数字: ";
    std::cin >> i;
    for (int ii = 1; ii <= i; ii++){
        for (int jj = 1; jj <= ii; jj++) {
            cout << to_string(jj) << "*" << to_string(ii) << "=" << to_string(ii*jj) << "\t";
        }
        cout << "\n";
    }
}
