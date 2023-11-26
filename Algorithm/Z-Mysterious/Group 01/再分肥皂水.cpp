// 现在有t毫升肥宅快乐水，要均分给 n名同学。每名同学需要 2个杯子。现在想知道每名同学可以获得多少毫升饮料（严格精确到小数点后 3位），以及一共需要多少个杯子。

#include <iostream>
using namespace std;

int main(){
    double n;
    int m;
    cin >> n >> m;
    double avg = n / m;
    printf("%.3lf\n", avg);
    printf("%d", m*2);
    return 0;
}