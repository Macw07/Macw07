#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
struct dimension{
    double x;
    double y;
    double z;
};

dimension arr[50005];
double total;

bool cmp(dimension a, dimension b){
    return a.z < b.z;
}

double dis(dimension a, dimension b){
    return sqrt(pow((a.x-b.x), 2) + pow((a.y-b.y), 2) + pow((a.z-b.z), 2));
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i].x >> arr[i].y >> arr[i].z;
    sort(arr, arr+n, cmp);
    for (int i=0; i<n-1; i++){
        total += dis(arr[i], arr[i+1]);
    }
    printf("%.3f", total);
    return 0;
}