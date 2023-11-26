#include <iostream>
#include <algorithm>
using namespace std;

void recursion(int n, string s){
    if (n == 0) return ;
    cout << s;
    recursion(n-1, s);
    return ;
}

int main(){
    int n;
    cin >> n;
    cout << "dog ";
    recursion(n, "hug ");
    cout << "fish ";
    recursion(n, "me ");
    return 0;
}