#include <iostream>
#include <algorithm>
using namespace std;

int arr1[10100];
int arr2[10100];
int ans[10100];

bool cmp(string a, string b){
    int la = a.size(), lb = b.size();
    if (la!=lb){
        return la > lb;
    }
    for (int i=0; i<lb; i++){
        if (a[i] < b[i]){
            return false;
        }
    }
    return true;
}

string deduct(string a, string b){   
    string s;
    int la=a.size(), lb=b.size();
    int lc = max(la, lb);

    for (int i=la; i>=0; i--) arr1[i] = a[la-i] - '0';
    for (int i=lb; i>=0; i--) arr2[i] = b[lb-i] - '0';
    
    for (int i=0; i<=lc; i++){
        if (arr1[i] < arr2[i]){
            arr1[i+1] --;
            arr1[i] += 10;
        }
        ans[i] = arr1[i] - arr2[i];
    }

    while(ans[lc] == 0) lc--;
    for (int i=lc; i>0; i--) s += ans[i] + '0';

    if (lc < 1) return "0";
    return s;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(!cmp(a, b)){
        swap(a, b);
        cout << "-";
    }
    cout << deduct(a, b);
    return 0; 
}