#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int sum1=0, sum2=0, l1=0, l2=0;
    for (int i=1; i<=n; i++){
        if (i%k==0){
            sum1 += i;
            l1++;
        } else{
            sum2 += i;
            l2++;
        }
    }
    // cout << sum1 << sum2;
    double avg1 = double(sum1)/double(l1);
    double avg2 = double(sum2)/double(l2);
    printf("%.1lf %.1lf", avg1, avg2);
    return 0;
}