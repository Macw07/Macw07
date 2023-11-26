#include <iostream>
#include <algorithm>
using namespace std;

string str, ans;
string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};
int d[] = {0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
long long arr[10005], ptr;
bool flag;
string add(int n){
    string s;
    if (n == 0) s += '0';
    while(n){
        s += n % 10 + '0';
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
};

int convert(string k){
    int sum = 0;
    for (int i=0; i<k.size(); i++){
        sum = sum * 10 + k[i]-'0';
    }
    return sum;
}

int main(){
    while(cin >> str){
        if (str == ".") break;
        for (int i=1; i<=26; i++){
            if (str == nums[i]){
                arr[ptr++] = d[i];
                break;
            }
        }
    }
    sort(arr, arr+ptr);
    for (int i=0; i<ptr; i++){
        if (flag){
            printf("%.2d", arr[i]);
        } else{
            if (arr[i]){
                printf("%d", arr[i]);
                flag = 1;
            }
        }
    }
    if (!flag) cout << "0" << endl;
    return 0;
}