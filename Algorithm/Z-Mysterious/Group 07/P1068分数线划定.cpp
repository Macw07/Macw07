#include <iostream>
#include <algorithm>
using namespace std;

int n, m, above;
int cnt = 0, line = 0;
struct inter{
    int id;
    int score;
};

inter arr[5005];

bool cmp(inter a, inter b){
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main(){
    cin >> n >> m;
    above = m * 1.5;
    for (int i=0; i<n; i++){
        cin >> arr[i].id >> arr[i].score;
    }
    sort(arr, arr+n, cmp);
    above--;
    cout << arr[above].score << " ";
    cnt = above;
    for (int i=above; i<=n; i++){
        if (arr[i].score == arr[above].score) cnt++;
        else break;
    }
    cout << cnt << endl;
    for (int i=0; i<cnt; i++){
        cout << arr[i].id << " " << arr[i].score << endl;
    }
    return 0;
}