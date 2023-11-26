/* 小码君来到书店，书架上从左到右摆放n(n<=1000)本书，编号依次为1到n，
每本书都有一个价格，书店老板想考考小码君的数学能力，问了小码君m次，
每次让他求出编号到1到R之间(包括1和R)（10<=R<=1000）所有的书的总价是多少，请你帮帮小码君吧。*/
#include <iostream>
using namespace std;

int main(){
    int book_num;
    cin >> book_num;
    int arrA[book_num+5];
    for (int i=0; i<book_num; i++){
       cin >> arrA[i];
    }
    int times;
    cin >> times;
    for (int i=0; i<times; i++){
        int num;
        cin >> num;
        int count = 0;
        for (int j=0; j<num; j++){
            count += arrA[j];
        }
        cout << count << endl;
    }
}