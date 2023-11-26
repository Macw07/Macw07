#include <iostream>
using namespace std;

int n;

int sum(int k){
    int sum = 0;
    for (int i=1; i<k; i++){
        if (k % i == 0) sum += i;
    }
    return sum;
}

int main(){
    cin >> n;
    for (int i=n+1; ;i++){
        int crt = sum(i);
        if (i == sum(crt) && i != crt){
            cout << i << " " << crt << endl;
            return 0;
        }
    }
    return 0;
}