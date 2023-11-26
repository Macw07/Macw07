#include <iostream>
using namespace std;

int n, m;  // n表示口袋的容量。
int count_p = 0;  // count_p表示口袋所能装的质数的数量。

bool isPrime(int num){
	if (num <= 1){
		// 所有小于等于1的数字都不是质数。
		return false;
	}
	if (num == 2){
		// 二是特殊的质数。
		return true;
	}
	for (int i=2; i*i<=num; i++){
		if (num % i == 0){
			// 有因数，则判定这个数肯定不是质数。
			return false;
		}
	}
	// 当这个数没有任何的因数时，则返回真。
	return true;
}

int main(){
    cin >> n >> m;
    int begin = min(n, m);
    int end = max(n, m);
    for (int i=begin; i <= end; i++){
        if (isPrime(i)){
            count_p += 1;
        }
    }
    cout << count_p << endl;
    return 0;
}