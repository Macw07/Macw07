#include <iostream>
using namespace std;

int arr[4005];

int main(){
    int n, sum=0, count=0;
    cin >> n;
    for (int i=0; sum < n*n; i++){
        cin >> arr[i];
        sum += arr[i];
        count++;
    }
    bool sta = 0;
    int c = 0;
    for (int i=0; i<count; i++){
        while(arr[i]--){
            c++;
            if (c == n+1){
                c = 1;
                cout << endl;
            }
            if (sta == 1){
                cout << '1';
            } else{
                cout << '0';
            }
        }
        if (sta == 0){
            sta = 1;
        } else{
            sta = 0;
        }
    }
    return 0;
}