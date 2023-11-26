#include <iostream>
#include <algorithm>
using namespace std;

struct channel{
    int begin, end;
};

channel arr[105];

bool cmp(channel a, channel b){
    return a.end < b.end;
}

int main(){
    int n, idk;
    while (true){
        cin >> n;
        if (n == 0) break;
        for (int i=0; i<n; i++){
            cin >> arr[i].begin >> arr[i].end;
        }
        sort(arr, arr+n, cmp);
        int count=0, end=-1;
        for (int i=0; i<n; i++){
            if (arr[i].begin >= end){
                end = arr[i].end;
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}