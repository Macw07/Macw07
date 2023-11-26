#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, pointer = 0;

struct logs{
    string name;
    string id;
    string gender;
    string time;
};

struct students{
    string name;
    string id;
    int times;
};

logs arr[10005];
students stud[10005];

bool cmp1(logs a, logs b){
    if (a.id == b.id){
        return a.time < b.time;
    }
    return a.id < b.id;
}

bool cmp2(students a, students b){
    if (a.times == b.times){
        return a.id < b.id;
    }
    return a.times > b.times;
}

int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        string a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = (logs){a, b, c, d};
    }
    sort(arr, arr+n, cmp1);
    for (int i=0; i<n; i++){
        if (arr[i].id == arr[i-1].id && arr[i].time == arr[i-1].time) continue;
        if (arr[i].id != arr[i-1].id) stud[pointer++] = (students){arr[i].name, arr[i].id, 0};
        for (int j=0; j<pointer; j++){
            if (stud[j].id == arr[i].id){
                stud[j].times++;
                break;
            }
        }
    }
    sort(stud, stud+pointer, cmp2);
    for (int i=0; i<pointer; i++){
        cout << stud[i].name << " " << stud[i].id << " " << stud[i].times << endl;
    }
    return 0;
}