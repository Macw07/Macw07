#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int position = n % (m + 1);
    if (position == 0) cout << "Defeat" << endl;
    else cout << "Victory" << endl;
    return 0;
}

