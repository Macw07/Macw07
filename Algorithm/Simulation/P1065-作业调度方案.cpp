#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int order[500];  // 系统给定的零件加工顺序
struct component{  // 每个零件的信息
    int process;
    int time_consuming;
};
int machine[25][100005];  // 表示机器i在第j个时间点是否有空
int steps[25];  // 表示第i个机器已经执行到了第steps[i]个程序
int last_time[25];  // 表示第i个工件是在第last_time[i]时候加工完成的
component information[25][25];  // 表示第i个零件的第j道工序的对应机器和所消耗时间
int ans = 0;  // 最终答案

int main(){
    // 输入初始化
    scanf("%d %d", &m, &n);
    for (int i=1; i<=m*n; i++){
        scanf("%d", &order[i]);
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            scanf("%d", &information[i][j].process);
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            scanf("%d", &information[i][j].time_consuming);
        }
    }

    // 超级大模拟
    for (int i=1; i<=m*n; i++){
        int current = order[i];  // 当前需要加工的零件
        steps[current] += 1;
        int machine_id = information[current][steps[current]].process;  // 当前这个零件的这个步骤的对应机器
        int time_consuming = information[current][steps[current]].time_consuming;  // 当前这个零件的这个步骤的所需时间
        int time_interval = 0;
        for (int j=last_time[current]+1; ; j++){  // 遍历之后的时间
            if (machine[machine_id][j] == 0) time_interval += 1;  // 表示这个时间区间的能力
            else time_interval = 0;  // 由于不满足条件，所以需要立刻归位0，重新开始计数
            if (time_interval >= time_consuming){
                // 这一段时间是可以的，那我们就占用这一段时间。
                for (int k=j-time_consuming+1; k<=j; k++) machine[machine_id][k] = 1;
                ans = max(j, ans);
                last_time[current] = j;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}