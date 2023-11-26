
// 在我们提交题目的时候每个测试点都会收到一个反馈。反馈的结果有好多种。

// Accepted 简称 AC，表示正确
// Wrong Answer 简称 WA，表示错误
// Presentation Error 简称 PE，表示格式错误
// Time Limit Exceeded 简称 TLE，表示时间超限
// Runtime Error 简称 RE，表示运行错误
// Compile Error 简称 CE，表示编译错误
// Memory Limit Exceeded 简称 MLE,表示内存超限。
// 请输出每个评测结果的名称、简称和含义。

#include <stdio.h>
using namespace std;

int main(){
    printf("Accepted AC 正确\n");
    printf("Wrong Answer WA 错误\n");
    printf("Presentation Error PE 格式错误\n");
    printf("Time Limit Exceeded TLE 时间超限\n");
    printf("Runtime Error RE 运行错误\n");
    printf("Compile Error CE 编译错误\n");
    printf("Memory Limit Exceeded MLE 内存超限\n");
    return 0;
}