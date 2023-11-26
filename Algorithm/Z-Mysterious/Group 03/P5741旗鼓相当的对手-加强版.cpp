#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int n;

struct student{
    string name;
    int chinese, math, english, total;
};

student arr[1005];

void match(){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            // 判断成绩
            if (abs(arr[i].total-arr[j].total) > 10) continue;
            if (abs(arr[i].chinese-arr[j].chinese)<=5 && abs(arr[i].math-arr[j].math)<=5 && abs(arr[i].english-arr[j].english)<=5){
                cout << arr[i].name << " " << arr[j].name << endl;
            }
        }
    }
}
int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].chinese >> arr[i].math >> arr[i].english;
        arr[i].total = arr[i].chinese + arr[i].math + arr[i].english;
    }
    match();
    return 0;
}