// 将 n 元人民币换成 1元、2元、5元的零钱，编程计算共有多少种方法？
#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    int n;
    cin >> n;
    for (int i = 0; i <= n / 1; i++)
    {
        for (int j = 0; j <= n / 2; j++)
        {
            for (int k = 0; k <= n / 5; k++)
            {
                if (i + j*2 + k*5 == n){
                    count ++;
                }
            }
        }
    }
    cout << count << endl;
}