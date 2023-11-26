#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
struct node{
    int a, b, c;
} temp;

node Sort(node t){
    int ma = max(t.a, max(t.b, t.c));
    int mi = min(t.a, min(t.b, t.c));
    int total = t.a + t.b + t.c;
    t.a = mi, t.c = ma, t.b = total - ma - mi;
    return t;
}

node Swap(int k, node t){
    int temp = 0;
    if (k == 1){
        temp = t.a;
        t.a = t.b;
        t.b = temp;
    } else if (k == 2){
        temp = t.b;
        t.b = t.c;
        t.c = temp;
    } else if (k == 3){
        temp = t.a;
        t.a = t.c;
        t.c = temp;
    }
    return t;
}

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

void Calc(node t){
    int g1 = gcd(t.a, t.b);
    int g2 = gcd(t.b, t.c);
    const int mod = 100000;
    int g3 = g1 * g2 % mod + t.a + t.b + t.c;
    cout << g3 << endl;
    return ;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> temp.a >> temp.b >> temp.c >> m;
        while(m--){
            string c;
            cin >> c;
            if (c == "S")  temp = Sort(temp);
            else if (c == "Sw"){
                int t;
                cin >> t;
                temp = Swap(t, temp);
            } else if (c == "C") Calc(temp);
        }
    }
    return 0;
}