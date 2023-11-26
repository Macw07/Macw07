#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    string k;
    cin >> n >> k;
    for (int i = 0; i < k.size(); i++)
    {
        if (i !=0 && k[i] != '0') cout << '+';
        if (k[i] == '0') continue;
        printf("%d*%d^%lu", k[i] - 48, n, k.size() - i - 1);
    }
    return 0;
}