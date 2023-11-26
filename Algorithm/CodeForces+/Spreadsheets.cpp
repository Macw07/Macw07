#include <iostream>
#include <cmath>
using namespace std;

void convert(string str);

int main(){
    int n;
    cin >> n;
    string str;
    for (int i=0; i<n; i++){
        cin >> str;
        convert(str);
    }
    return 0;
}

void convert(string str){
    bool flag=0;
    for (int i=0; i<str.size(); i++){
        if (str[i] == 'C' && i != 1){
            flag=1;
            break;
        }
    }
    if (str[0]=='R' && str[1] >= '0' && str[1] <= '9' && flag){
        string str1;
        string str2;
        int i=1;
        while (str[i]!='C'){
            str1 += str[i];
            i++;
        }
        i++;
        while (str[i]){
            str2 += str[i];
            i++;
        }
        int number=0;
        for (int i=0; i<str2.size(); i++){
            number = number*10 + (int(str2[i])-48);
        }
        int arr[100] = {}, pointer=0;
        while (number>0){
            if (number%26==0){
                arr[pointer] = 26;
                number-=1;
            } else{
                arr[pointer] = number%26;
            }
            number /= 26;
            pointer++;
        }
        for (int i=pointer-1; i>=0; i--){
            cout << char(arr[i]+64);
        }
        cout << str1 << endl;
    } else {
        string str1;
        string str2;
        int i=0;
        while (str[i] >= 'A' && str[i] <= 'Z'){
            str1 += str[i];
            i++;
        }
        while (str[i]){
            str2 += str[i];
            i++;
        }
        cout << 'R' << str2 << 'C';
        int sum=0;
        for (int i=str1.size()-1, j=0; i>=0; i--, j++){
            if (str1[i]){
                sum += (str[i]-64)*pow(26, j);
            } else{
                break;
            }
        }
        cout << sum << endl;
    }
    return;
}