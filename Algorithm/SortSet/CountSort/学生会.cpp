/* # 【深基9.例1】选举学生会
学校正在选举学生会成员，有 $n(n\le 999)$ 名候选人，每名候选人编号分别从 1 到 $n$，现在收集到了 $m(m<=2000000)$ 张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。
*/

#include <iostream>
using namespace std;

int arr[1000] = {};

int main(){
    int n, m, t;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> t;
        arr[t-1] += 1;
    }
    for (int i=0; i<1000; i++){
        while (arr[i]>0){
            cout << i+1 << " ";
            arr[i]--;
        }
    }
}