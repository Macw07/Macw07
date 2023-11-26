#include <cstring>
#include <iostream>

using namespace std;

char s[1000005];

int main() {
    cin >> s;
    int ans = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == 'a')
            ++ans;
    }
    cout << ans << endl;
    return 0;
}