#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long total = 0;

// 这道题竟然是一道数学题，没想到。GD
// 因为一个数的因数一半是成双成对出现的，所以特判一下应该是可以的

int prime1(int k){
    total = 0;
    for (int i=1; i<=k; i++){
        if (k % i == 0) total++;
    }
    return total;
}

void prime2(int k){
    if (k == 1) {total++; return;}
    for (int i=1; i*i<=k ; i++){
        if (k % i == 0){
            total += 2;
            if (i * i == k) total--;
        }
    }
}

int prime3(int k){
    total = 0;
    // 质因数分解
    int i=2;
    int sum = 1;
    int temp = 0;
    int now = 0;
    while(k != 1){
        while(k % i == 0){
            if (i == now) temp++;
            else {sum *= temp+1; now = i; temp = 1;}
            k /= i;
        }
        if (i == 2) i++;
        else i += 2;
    }
    if (i == now) temp++;
    else {sum *= temp+1; now = i; temp = 1;}
    total += sum;
    return total;
}

int arr[10000005] = {};
int prime4(int k){
    int sum = 0;
    for (int i=1; i<=k; i++){
        for (int j=i; j<=k; j+=i){
            arr[j]++;
        }
        sum += arr[i];
    }
    return sum;
}

long long prime5(int k){
    int sum = 0;
    for (int i=1; i<=k; i++){
        sum += k / i;
    }
    return sum;
}

int main(){
    cin >> n;
    cout << prime5(n);
    return 0;
}