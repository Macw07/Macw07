#include <iostream>
#include <algorithm>
using namespace std;

int n, s, total;
struct node{
    int remain, price;
} product[100000];

bool cmp(node a, node b){
    return a.price < b.price;
}

int main(){
    cin >> n >> s;
    for (int i=1; i<=n; i++) cin >> product[i].remain >> product[i].price;
    sort(product+1, product+n+1, cmp);
    // 累加即可
    for (int i=1; i<=n; i++){
        int pro = product[i].price * product[i].remain;
        if (pro <= s) {
            total += product[i].remain;
            s -= pro;
        } else{
            total += s / product[i].price;
            break;
        }
    }
    cout << total << endl;
    return 0;
}