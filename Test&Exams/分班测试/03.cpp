/*
按学号从小到大给出一个班 n 个同学的语数英成绩，
请计算他们的总分并根据总分输出前5名同学的姓名和总分
（如果总分相同，则语文成绩高者排名靠前；
如果语文成绩相同，则数学成绩高者排名靠前；
如果数学成绩相同，则英语成绩高者排名靠前；
若英语成绩相同，则学号小的排名靠前）
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct student{
    string name;
    int c, m, e;
    int total, id;
} arr[55];

bool cmp(student a, student b){
    if (a.total == b.total){
        if (a.c == b.c){
            if (a.m == b.m){
                if (a.e == b.e){
                    return a.id < b.id;
                }
                return a.e > b.e;
            }
            return a.m > b.m;
        }
        return a.c > b.c;
    }
    return a.total > b.total;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        string name;
        int c, m, e;
        cin >> name >> c >> m >> e;
        arr[i] = (student){name, c, m, e, c+m+e, i};
    }
    sort(arr+1, arr+n+1, cmp);
    for (int i=1; i<=5; i++){
        cout << arr[i].name << " " << arr[i].total << endl;
    }
    return 0;
}