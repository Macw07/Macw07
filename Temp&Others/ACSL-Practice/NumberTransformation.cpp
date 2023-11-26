#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int p;
string num;

int main(){
    while(cin >> num >> p){
        int len = num.size();
        for (int i=0; i<len-p; i++){
            int k = (num[i] - '0') + (num[len-p] - '0');
            k %= 10;
            num[i] = k + '0';
        }
        for (int i=len-p+1; i<len; i++){
            int k = abs((num[i] - '0') - (num[len-p] - '0'));
            k %= 10;
            num[i] = k + '0';
        }
        cout << num << endl;
    }
    return 0;
}