#include <iostream>
using namespace std;

int arr[10005] = {};
int main(){
    int begin, end, c=0;
    cin >> begin >> end;
    for (int i=begin; i<=end; i++){
        if (i%4==0 && i%100!=0 || i%400==0){
            arr[c] = i; 
            c++;
        }
    }
    cout << c << endl;
    for (int i=0; i<c; i++){
        cout << arr[i] << " ";
    }
    return 0;
}