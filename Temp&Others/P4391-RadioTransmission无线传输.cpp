#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6;

string str;
int n, nextval[MAXN + 5];

int main(){
	cin >> n >> str;
    str = " " + str;
	// nextval[1] = -1;
	int k = 0;
	for (int i=2; i<=n; i++){
		while (k && str[i] != str[k+1]) k = nextval[k];
		if (str[i] == str[k+1]) k++;
		nextval[i] = k;
	}
	cout << n - nextval[n] << endl;
	return 0;
}