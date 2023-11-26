#include <iostream>

int main(){
    double n;
    std::cin >> n;
    if (n < 0){
        std::printf("%.2f", n*-1);
    } else{
        std::printf("%.2f", n);
    }
    return 0;
}