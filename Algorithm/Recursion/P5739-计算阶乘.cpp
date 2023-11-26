#include <iostream>
using namespace std;

// 由于本题的数据量较小，因此可以使用int类型。
int factorial(int n){
    if (n == 1){
        return n;
    }
    return n * factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}