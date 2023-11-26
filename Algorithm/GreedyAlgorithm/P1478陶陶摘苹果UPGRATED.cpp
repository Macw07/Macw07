#include <iostream>
#include <algorithm>
using namespace std;

struct apple{
    int x, y;
};

bool cmp(apple a, apple b){
    return a.y < b.y;
}

apple arr[5005] = {};

int main(){
    int n, s, a, b, t1, t2, c=0;
    cin >> n >> s >> a >> b;
    for (int i=0; i<n; i++){
        cin >> t1 >> t2;
        apple a = {t1, t2};
        arr[i] = a;
    }
    sort(arr, arr+n, cmp);
    // for (int i=0; i<n; i++){
    //     cout << arr[i].y << endl;
    // }
    for (int i=0; i<n; i++){
        if (a + b >= arr[i].x){
            s -= arr[i].y;
            if (s >= 0){
                c++;
            } else{
                cout << c;
                return 0;
            }
        }
    }
    cout << c;
    return 0;
}