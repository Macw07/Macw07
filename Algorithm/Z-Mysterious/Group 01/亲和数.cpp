/* 自然数a的因子是指能整除a的所有自然数，但不含a本身。例如12的因子为：1,2,3,4,6。
若自然数a的因子之和为b，而且b的因子之和又等于a，则称a,b为一对“亲和数” ,并且a和b不相等 */
#include <iostream>
using namespace std;

int main()
{ 
     int a;
     int b;
     cin >> a >> b;
     int suma = 0;
     int sumb = 0;

     for (int i = 1; i <= a; i++)
     {
         if (a % i == 0)
         {
             suma += i;
         }
     }
     for (int i = 1; i <= b; i++)
     {
         if (b % i == 0)
         {
             sumb += i;
         }
     }

     if ( a != b && suma == sumb) {
         cout << "Yes" << endl;
     }else{
         cout << "No" << endl;
     }
}