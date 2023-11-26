#include <iostream>
#include <algorithm>
using namespace std;

// 这道题设计的原意想让我们使用结构体排序，但是可以直接通过if语句的判断，节省时间和精力。

int main(){
    string name, su, wes, mname;
    int avg, ass, pap, mm=0;
    int n, total=0, sum=0;
    cin >> n;
    for (int i=0; i<n; i++){
        sum = 0;
        cin >> name >> avg >> ass >> su >> wes >> pap;
        if (avg > 80 && pap >= 1) sum += 8000;
        if (avg > 85 && ass > 80) sum += 4000;
        if (avg > 90) sum += 2000;
        if (avg > 85 && wes == "Y") sum += 1000;
        if (ass > 80 && su == "Y") sum += 850;
        total += sum;
        if (sum > mm){
            mm = sum;
            mname = name;
        }
    }
    printf("%s\n%d\n%d", mname.c_str(), mm, total);
    return 0;
}