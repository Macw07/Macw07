#include <iostream>
using namespace std;

int main(){
    int begin, end;
    cin >> begin >> end;
    if (begin > end){
        cout << "Error!" << endl;
        return 0;
    }
    for (int i=begin; i<=end; i++){
        cout << i << endl;
    }
    return 0;
}