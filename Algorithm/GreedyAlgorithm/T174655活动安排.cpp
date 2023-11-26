#include <iostream>
#include <algorithm>
using namespace std;

struct classroom{
    int start, end;
};
classroom arr[1005] = {};

bool cmp(classroom a, classroom b){
    return a.end < b.end;
}

int main(){
    int n, s, b, count=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s >> b;
        classroom c = {s, b};
        arr[i] = c;
    }
    sort(arr, arr+n, cmp);
    classroom temp = {-1, -1};
    for (int i=0; i<n; i++){
        if (arr[i].start > temp.end){
            temp = arr[i];
            // cout << arr[i].start << " " << arr[i].end << endl;
            count++;
        } 
    }
    // for (int i=0; i<n; i++){
    //     printf("%d %d\n", arr[i].start, arr[i].end);
    // }
    cout << count;
    return 0;
}