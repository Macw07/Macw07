#include <iostream>
#include <algorithm>
using namespace std;

string str;
int nums[10005], a, b, c, d, l;
char capital[10005];
char lowercase[10005];
char others[10005];

int main(){
    cin >> str;
    l = str.length();
    for (int i=0; i<l; i++){
        if (str[i] >= 'a' && str[i] <= 'z') lowercase[c++] = str[i];
        else if (str[i] >= 'A' && str[i] <= 'Z') capital[b++] = str[i];
        else if (str[i] >= '0' && str[i] <= '9') nums[a++] = str[i] - '0';
        else others[d++] = str[i];
    }
    sort(nums, nums+a); sort(capital, capital+b);
    sort(lowercase, lowercase+c); sort(others, others+d);
    for (int i=0; i<c; i++) cout << lowercase[i]; 
    for (int i=0; i<b; i++) cout << capital[i]; 
    for (int i=0; i<a; i++) cout << nums[i]; 
    for (int i=0; i<d; i++) cout << others[i]; 
    cout << endl;
    return 0;
}