#include <iostream>
using namespace std;

int a[100] = {};
int arr[100] = {};
int sumn = 0;

void add(long long sum)
{
    int n = 0;
    while (sum)
    {   
        a[n] = sum % 10;
        sum /= 10;
        n++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] += a[i];
        if (arr[i] >= 10){
            arr[i] -= 9;
            arr[i + 1] += 1;
        } 
    }
}

long long sum = 1;
void FACT(int n)
{
    if (!n)
    {
        // cout << sum << endl;
        // add(sum);
        return;
    }
    // sum = sum * n
    for (int i=1; i<=n; i++){
        add(n);
    }
    FACT(n - 1);
}
int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        sum = 1;
        FACT(i);
        for (int j = 0; j < 100; j++)
        {
            cout << arr[j];
        }
        cout << endl;
    }
    return 0;
}