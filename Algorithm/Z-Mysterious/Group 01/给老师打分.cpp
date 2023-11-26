/* 现在有 n(n≤100) 个学生给老师打分，分值从 0 到 100不等。
需要去掉一个最高分，去掉一个最低分（如果有多个最高或者最低分，也只需要去掉一个），
剩下的评分的平均数就是这位老师的得分。
现在输入学生人数和他们的打分，请输出老师的最后得分，精确到 2 位小数。（平均数，就是总分/n） */
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int count;
    cin >> count;
    int score[count];
    int len = sizeof(score)/sizeof(score[0]);
    for (int i=0; i<len; i++){
        cin >> score[i];
    }
    int max = 1;
    int min = 0x7f7f7f7f;
    for (int i=0; i<len; i++) {
        if (score[i] > max){
            max = score[i];
        }
        if (score[i] < min){
            min = score[i];
        }
    }
    int sum = 0;
    for (int i=0; i<len; i++) {
        sum += score[i];
    }
    sum = sum - min - max;
    float average = float(sum)/(len-2);
    printf("%.2f\n", average);
}