#include <iostream>

int main(){
    char c;
    std::cin >> c;
    if (c >= 'a' && c <= 'z'){
        std::cout << char(c-32);
    } else if(c >= 'A' && c <= 'Z'){
        std::cout << char(c+32);
    }
    return 0;
}