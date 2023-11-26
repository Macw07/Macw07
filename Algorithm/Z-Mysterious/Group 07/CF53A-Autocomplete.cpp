#include <iostream>
#include <algorithm>
using namespace std;

string ori;
int n;
string arr[105];

int main(){
    cin >> ori;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i=0; i<n; i++){
        if (arr[i].substr(0, ori.size()) == ori){
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << ori << endl;
    return 0;
}