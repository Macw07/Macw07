#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
    s.insert(1);
    s.insert(3);
    s.insert(5);
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++){
        cout << *it << endl;
    }
    it = s.begin();
    cout << *it << endl;
    return 0;
}