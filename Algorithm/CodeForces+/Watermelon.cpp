#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    if (n==2){
        cout << "NO";
        return 0;
    }
    if (n%2==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    return 0;
}