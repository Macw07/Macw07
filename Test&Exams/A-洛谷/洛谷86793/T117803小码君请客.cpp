#include <iostream>
// using namespace std;

int main(){
    int n, total=1;
    std::cin >> n;
    while(n--){
        int t;
        std::cin >> t;
        total += t;
    }
    std::cout << total;
    return 0;
}