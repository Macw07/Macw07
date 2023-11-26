#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n==0){
        printf("Today, I ate 0 apple.");
    } else if(n==1){
        printf("Today, I ate 1 apple.");
    }else{
        printf("Today, I ate %d apples.", n);
    }
    return 0;
}