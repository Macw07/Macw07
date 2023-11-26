#include <iostream>
using namespace std;

int main(){
    int a, b, t;
    cin >> a >> b;
    while (a % b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    cout << b;
    return 0;
}

// #include <iostream>4
// using namespace std;

// //辗转相除法(欧几里得算法) 
// int gcd(int a,int b){
// 	if(a%b==0){
// 		return b;
// 	}
// 	gcd(b,a%b);
// }

// int main(){
// 	int a,b;
// 	cin>>a>>b;
// 	cout<<gcd(a,b);
// 	return 0;
// }