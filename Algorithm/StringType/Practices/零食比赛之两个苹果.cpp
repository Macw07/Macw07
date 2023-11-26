/* 
有2个苹果是欢喜冤家，天天遇到就开始吵架，今天，他们又遇到了，又因为一个问题而吵架了，
苹果A说任意3个数字都可以组成三角形，就是三角形的3条边，
苹果B说不可能，他们就不停的争吵。你能帮忙调解这2个苹果吗
 */

#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b>c && a+c > b && b+c >a){
        cout << "B" << endl;
    } else {
        cout << "A" << endl;
    }
}