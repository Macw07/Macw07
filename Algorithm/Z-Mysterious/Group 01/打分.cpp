#include <iostream>
using namespace std;

int main(){
    int n, max=0, min=0x7f7f7f, t;
    cin >> n;
    double sum=0, ans;
    for (int i=0; i<n; i++){
        cin >> t;
        sum += t;
        if (t>max){
            max = t;
        } else if(t<min){
            min = t;
        }
    }
    ans = (sum-max-min)/(n-2);
    printf("%.2lf",ans);
    return 0;
}