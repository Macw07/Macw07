#include <iostream>
#include <cmath>
using namespace std;

int m, s, t, r;
int current;

void check_end(){
    if (current >= s){
        cout << "Yes" << endl;
        cout << r - t << endl;
        exit(0);
    }
    return ;
}

int main(){
    scanf("%d %d %d", &m, &s, &t);
    r = t;
    // 模拟 + 贪心 即可。
    while(t){
        // 跑完了，结束循环，输出结果。
        check_end();
        
        if (m / 10){
            current += 60;
            t -= 1;
            // check_end();
            m = m - 10;
            // continue;
        }
        // 如果剩下的时间可以使用技能，则使用一次技能。
        if ((m + t/2*4) / 10){
            double need = 10 - m;
            double tmp = ceil(need / 4);
            t -= tmp;
            m += tmp * 4;
        }
        // 如果剩下的时间没办法使用技能了，则直接跑步。
        else {
            current += 17;
            t -= 1;
        }
    }
    cout << "No" << endl;
    cout << current << endl;
    return 0;
}