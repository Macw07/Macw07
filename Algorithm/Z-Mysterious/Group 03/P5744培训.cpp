#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, age, score;
    string name;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> name >> age >> score;
        score = min(int(score*1.2), 600);
        cout << name << " " << age+1 << " " << score << endl;
    }
    return 0;
}