/* NOI2130 即将举行。为了增加观赏性，CCF 决定逐一评出每个选手的成绩，并直播即时的获奖分数线。本次竞赛的获奖率为 $w\%$，即当前排名前 $w\%$ 的选手的最低成绩就是即时的分数线。
更具体地，若当前已评出了 $p$ 个选手的成绩，则当前计划获奖人数为 $\max(1, \lfloor p * w \%\rfloor)$，其中 $w$ 是获奖百分比，$\lfloor x \rfloor$ 表示对 $x$ 向下取整，$\max(x,y)$ 表示 $x$ 和 $y$ 中较大的数。如有选手成绩相同，则所有成绩并列的选手都能获奖，因此实际获奖人数可能比计划中多。
作为评测组的技术人员，请你帮 CCF 写一个直播程序。*/

#include <iostream>
using namespace std;

int arr[600] = {};

int main(){
    int n, w, t;
    int per=0, count=0;
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        count=0;
        cin >> t;
        arr[t]+=1;
        per = i*w*0.01;
        if (per<1){
            per=1;
        }
        bool flag=1;
        int sum=0;
        for (int j=600; j>=0; j--){
            sum += arr[j];
            if (sum>=per){
                cout << j << " ";
                flag=0;
                break;
            }
        }   
    }
}