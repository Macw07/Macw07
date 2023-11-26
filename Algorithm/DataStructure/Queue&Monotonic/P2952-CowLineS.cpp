#include <iostream>
#include <deque>
using namespace std;

int n, cnt, c;
char a, b;
deque<int> que;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if (a == 'A') {
            cin >> b;
            cnt += 1;
            if (b == 'L') que.push_front(cnt);
            else que.push_back(cnt);
        } else{
            cin >> b >> c;
            if (b == 'L')  while(c--) que.pop_front();
            else while(c--) que.pop_back();
        }
    }
    while(!que.empty()){
        cout << que.front() << endl;
        que.pop_front();
    }
    return 0;
}