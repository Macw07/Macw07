#include <iostream>
using namespace std;

int main(){
    int begin, end;
    int count=0, arr[1005] = {};
    cin >> begin >> end;
    for (int i=begin; i<=end; i++){
        if (i%4==0 && i%100 != 0 || i%400 == 0){
            arr[count++] = i;
        }
    }
    cout << count << endl;
    for (int i=0; i<count; i++){
        cout << arr[i] << " ";
    }
    return 0;
}