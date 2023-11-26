#include <iostream>
#include <algorithm>
using namespace std;

// 服了这道题了，题干没说清楚。sos

int arr[1005];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int score, n;
    cin >> score >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        if (arr[i] == score){
            if (double(i)/n < 0.1){
                cout << "A" << endl;
            } else if (double(i)/n < 0.3){
                cout << "B" << endl;
            } else if (double(i)/n < 0.6){
                cout << "C" << endl;
            } else if (double(i)/n < 0.8){
                cout << "D" << endl;
            } else{
                cout << "E" << endl;
            }
            break;
        }
    }
    return 0;
}