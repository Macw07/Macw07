#include <iostream>
using namespace std;

int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int nums[2005] = {6};

int main(){
    int n, ans=0, t;
    cin >> n;
    for (int i=1; i<=2000; i++){
        t = i;
        while(t){
            nums[i] = nums[i] + arr[t%10];
            t /= 10;
        }
    }
    for (int i=0; i<1000; i++){
        for (int j=0; j<1000; j++){
            if (nums[i+j] + nums[i] + nums[j] + 4 == n){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}