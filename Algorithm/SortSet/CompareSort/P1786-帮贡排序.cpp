#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int id;
    string name;
    string status;
    int banggong;
    int level;
};

int n, ptr = 0;
node arr[150];
string names[] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
int times[] = {1, 2, 2, 4, 7, 25, 1000};

int change(string a){
	if (a == "BangZhu") return 0;
	if (a == "FuBangZhu") return 1;
	if (a == "HuFa") return 2;
	if (a == "ZhangLao") return 3;
	if (a == "TangZhu") return 4;
	if (a == "JingYing") return 5;
	if (a == "BangZhong") return 6;
}

bool cmp1(node a, node b){
    if (a.banggong != b.banggong){
        return a.banggong > b.banggong;
    } 
    return a.id < b.id;
}

bool cmp2(node a, node b){
    if (change(a.status) == change(b.status)){
        if (a.level == b.level) return a.id < b.id;
        return a.level > b.level;
    }
    return change(a.status) < change(b.status);
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].status >> arr[i].banggong >> arr[i].level;
        arr[i].id = i;
    }
    sort(arr+3, arr+n, cmp1);
    for (int i=0; i<n; i++){
        if (times[ptr] == 0) ptr++;
        arr[i].status = names[ptr];
        times[ptr]--;
    }
    sort(arr, arr+n, cmp2);
    for (int i=0; i<n; i++){
        cout << arr[i].name << " " << arr[i].status << " " << arr[i].level << endl;
    }
    return 0;
}