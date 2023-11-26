#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int n, k;
unsigned long long ans, l, r, mid;
queue<unsigned long long> results;

bool check(unsigned long long mid){
    return (1+mid)*mid/2 >= k;
}

int main(){
    ofstream dataFile;
    // dataFile.open("Q15.out", ofstream::app);
    // fstream file("Q15.out", ios::out);
    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        l = 0, r = k;
        while(l <= r){
            mid = (l+r) >> 1;
            if (check(mid)){
                ans = mid;
                r = mid-1;
            } else l = mid + 1;
            // cout << mid << endl;
        }
        // results.push(ans);
        printf("%lld\n", ans);
        dataFile << ans << endl;

    }
    // while(!results.empty()){
    //     printf("%lld\n", results.front());
    //     results.pop();
    // }
    return 0;
}