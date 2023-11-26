#include <iostream>
using namespace std;

long long arr[20005];
int head = 0;

int main(){
    int n, t, tt;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        if (t == 0){
            cin >> tt;
            head++;
            if (tt > arr[head-1]){
                arr[head] = tt;
            } else{
                arr[head] = arr[head-1];
            }
        } else if (t == 1){
            if (head-1 >= 0) head--;
        } else if (t == 2){
            cout << arr[head] << endl;
        }
    }
    return 0;
}