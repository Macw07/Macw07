#include <iostream>
using namespace std;

int s, t;

struct items{
    int value, weight;
};

items arr[25];

bool cmp(items a, items b){
    return a.value > b.value;
}

int main(){
    cin >> s >> t;
    for (int i=1; i<=s; i++){
        cin >> arr[i].value >> arr[i].weight;
    }
    sort(arr+1, arr+s+1, cmp);
    int totalweight = 0, totalvalue = 0;
    for (int i=1; i<=s; ){
        if (arr[i].weight >= 1){
            totalweight++;
            arr[i].weight--;
            totalvalue += arr[i].value;
            if (totalweight == t){
                cout << totalvalue << endl;
                return 0;
            }
        } else{
            i++;
        }
    }
    return 0;
}