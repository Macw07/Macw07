#include <iostream>

using namespace std;

int main() {
  int taskId;
  cin >> taskId;
  if (taskId == 1) {
    cout << 1999999999 << " " << 1999999999 <<endl;
  } else if (taskId == 2) {
    for (int i=0; i<1000000; i++) cout << 'a';
    cout << endl;
  } else if (taskId == 3) {
    cout << 100 << endl;
    for (int i=0; i<100; i++) cout << "1243 ";
    cout << endl;
  } else { // 这个 else 不会被执行
    cout << "OvoOvoovOovO" << endl;
  }
}