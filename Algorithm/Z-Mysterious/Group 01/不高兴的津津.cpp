#include <iostream>
using namespace std;

int main() {
    int a,b;
    int max_time = 0;
    int answer = 0;
    for(int i = 0;i < 7;++i) {
        cin >> a >> b;
        if(a + b > max_time && a + b > 8) {
            answer = i + 1;
            max_time = a + b;
        }
    }
    cout << answer;
    return 0;
}