#include <iostream>
using namespace std;

int main(){
    string a, b;
    int c, d;
    cin >> a >> b;

    if (a == "壹") c = 1;
    else if (a == "贰") c = 2;
    else if (a == "叁") c = 3;
    else if (a == "肆") c = 4;
    else if (a == "伍") c = 5;
    else if (a == "陆") c = 6;
    else if (a == "柒") c = 7;
    else if (a == "捌") c = 8;
    else if (a == "玖") c = 9;
    else if (a == "拾") c = 10;
    else c = 0;

    if (b == "壹") d = 1;
    else if (b == "贰") d = 2;
    else if (b == "叁") d = 3;
    else if (b == "肆") d = 4;
    else if (b == "伍") d = 5;
    else if (b == "陆") d = 6;
    else if (b == "柒") d = 7;
    else if (b == "捌") d = 8;
    else if (b == "玖") d = 9;
    else if (b == "拾") d = 10;
    else d = 0;

    cout << c + d << endl;
    return 0;
}