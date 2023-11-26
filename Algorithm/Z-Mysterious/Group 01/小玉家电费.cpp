#include <iostream>
using namespace std;

int main(){
    int n;
    double sum=0;
    cin >> n;
    for (int i=1; i<=n; i++){
        if (i <= 150){
            sum += 0.4463;
        } else if (i <= 400){
            sum += 0.4663;
        } else{
            sum += 0.5663;
        }
    }
    printf("%.1f", sum);
    return 0;
}