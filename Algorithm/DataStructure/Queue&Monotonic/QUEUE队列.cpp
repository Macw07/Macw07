#include <iostream>
#include <queue>
using namespace std;

// 定义一个队列
queue<int> obj;

int main(){
    obj.push(1);
    cout << obj.front() << endl;
    cout << obj.size() << endl;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    cout << obj.back() << endl;
    obj.pop();
    cout << obj.back() << endl;
    return 0;
}
