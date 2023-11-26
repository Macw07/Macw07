#include <iostream>
using namespace std;

int arr[10005] = {};
int n, s, avg, c=0, m;

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        s += arr[i];
    }
    avg = s/n;
    for (int i=0; i<n; i++){
        arr[i] -= avg;
        cout << arr[i] << " ";
    }
    cout << endl;
    int i=0, j=n-1;
    while (arr[i] == 0 && i < n) i++;
    while (arr[j] == 0 && j > 1) j--;
    while (i < j){
        arr[i+1] += arr[i];
        arr[i] = 0;
        c++;
        i++;
        while (arr[i] == 0 && i < j) i++;
    }
    cout << c;
    return 0;
}