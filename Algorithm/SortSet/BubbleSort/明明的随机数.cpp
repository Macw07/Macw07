/* 明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，
他先用计算机生成了 $N$ 个 $1$ 到 $1000$ 之间的随机整数 $(N\leq100)$，
对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。
然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。
 */

#include <iostream>
using namespace std;

int arr[105] = {0};
bool isExist(int num);
int N;

int main(){
    
    cin >> N;
    if (N<=0){
        return 0;
    }
    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        bool a = isExist(num);
        if (!a){
            arr[i] = num;
        } else {
            N -= 1;
            i -= 1;
        }
    }
    cout << N << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<N-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i=0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

bool isExist(int num){
    // cout << "CALL" << endl;
    bool flag = 0;
    for (int j=0; j<N; j++){
        if (num == arr[j]){
            flag = 1;
        }
    }
    return flag;
}