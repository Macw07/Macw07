#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

long long arr[1005][1005] = {};
long long ori[1005][1005];
stack<int> stk;
int dy[] = {-1, 0, 1};


int main(){
    int r;
    cin >> r;
    for (int i=0; i<r; i++){
        for (int j=0; j<i+1; j++){
            cin >> arr[i][j];
            ori[i][j] = arr[i][j];
        }
    }
    for (int i=r-2; i>=0; i--){
        for (int j=0; j<i+1; j++){
            arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
        }
    }
    cout << arr[0][0] << endl;

    for (int i=0; i<r; i++){
        for (int j=0; j<=i; j++){
            int index = 0;
            int nums = arr[i][j] - nums[i][j];
            for 
        }
    }
    return 0;
}