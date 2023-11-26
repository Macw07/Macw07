#include <iostream>
// using namespace std;

int main(){
    int n, dis=0, c=0;
    std::cin >> n;
    while(1){
        c++;
        dis += 10;
        if (dis >= n){
            break;
        }
        dis -= 5;
    }
    std::cout << c;
    return 0;
}