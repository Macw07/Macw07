/* 在已知一组整数中，有这样一种数非常怪，
它们不在第一个，也不在最后一个，'
而且刚好都比左边和右边相邻的数大，你能找到它们吗？ */
#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int arr[number];
    for (int i=0; i<number; i++){
       cin >> arr[i];
    }
    for (int i = 1; i < sizeof(arr)/sizeof(int); i++)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            cout << arr[i] << endl;
        }
    }
}