#include <iostream>
#include <algorithm>
using namespace std;

struct treasure{
    int  m, v;
    double m_v;
};

treasure arr[105] = {};

bool cmp(treasure a, treasure b){
    return a.m_v > b.m_v;
}

int main(){
    int n, t;
    double total=0, weight=0;
    cin >> n >> t;
    for (int i=0; i<n; i++){
        cin >> arr[i].m >> arr[i].v;
        arr[i].m_v = double(arr[i].v)/arr[i].m;
    }
    sort(arr, arr+n, cmp);
    for (int i=0; i<n; i++){
        if (weight + arr[i].m > t){
            total += arr[i].m_v*(t - weight);
            break;
        } else{
            total += arr[i].v;
            weight += arr[i].m;
        }
    }
    printf("%.2f", total);
    return 0;   
}