#include <iostream>
#include <algorithm>
using namespace std;

string a;
int b, ptr = 0, cnt=0;
int arr[5005];
long long sum = 0;

void div(string a, int b){
    for (int i=0; i<a.size(); i++){
        sum = sum * 10 + (a[i] - '0');
        arr[ptr++] = sum / b;
        sum %= b;
    }
    return;
}

int main(){
    cin >> a >> b;
    div(a, b);
    for (int i=0; i<ptr; i++){
        if (arr[i] != 0) {
            cnt = i;
            break;
        }
    }
    for (int i=cnt; i<ptr; i++){
        cout << arr[i];
    }
    if (cnt == ptr) cout << 0 << endl;
    return 0;
}