#include <iostream>
using namespace std;

int power(int num);

int main()

{
    int res;
    int num;
    cin >> num;
    res = power(num);
    cout << res << endl;
    return 0;
}

int power(int num)
{
    if (num == 1){
        return 1;
    }

    else {
        return power(num - 1) * num;
    }
}
