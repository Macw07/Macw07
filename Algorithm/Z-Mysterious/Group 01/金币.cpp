// 金币累加。

#include <iostream>
using namespace std;

int main(){
    int count = 0;
    int days, current=0, accumulate=1;
    cin >> days;
    for (int i=0; i<days; i++){
        if (current >= accumulate){
            current = 0;
            accumulate++;
        }
        count += accumulate;
        current++;
    }
    cout << count;
    return 0;
}