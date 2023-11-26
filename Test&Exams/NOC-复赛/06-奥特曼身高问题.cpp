#include <iostream>
#include <algorithm>
using namespace std;

struct atm{
    string name;
    int attack, age;
} arr[105];

bool cmp(atm atm1, atm atm2){
    if (atm1.attack == atm2.attack){
        return atm1.age < atm2.age;
    }
    return atm1.attack > atm2.attack;
}

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i].name >> arr[i].attack >> arr[i].age;
    sort(arr+1, arr+n+1, cmp);
    cout << arr[1].name << " " << arr[1].attack << " " << arr[1].age << endl;
    return 0;
}