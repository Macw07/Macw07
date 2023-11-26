#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[5] = {};
vector<char> path;
bool flag = false;
char sign[] = {'+', '-', '*', '/'};

int calculate(int a, int b, char c){
    switch(c){
        case '+': return b + a;
        case '-': return max(a, b) - min(a, b);
        case '*': return b * a;
        case '/': if (b != 0 && a >= b && a % b == 0) return a / b;
    }
    return -1000;
}

void special(){
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<4; k++){
                // 一二运算 三四运算 然后整体运算
                int a = calculate(arr[0], arr[1], sign[i]);
                int b = calculate(arr[2], arr[3], sign[j]);
                int c = calculate(a, b, sign[k]);
                if (c == 24){
                    if (arr[0] > arr[1]) printf("%d%c%d=%d\n", arr[0], sign[i], arr[1], a);
                    else printf("%d%c%d=%d\n", arr[1], sign[i], arr[0], a);
                    if (arr[2] > arr[3]) printf("%d%c%d=%d\n", arr[2], sign[j], arr[3], b);
                    else printf("%d%c%d=%d\n", arr[3], sign[j], arr[2], b);
                    if (a > b) printf("%d%c%d=%d\n", a, sign[k], b, c);
                    else printf("%d%c%d=%d\n", b, sign[k], a, c);
                    exit(0);
                };
            }
        }
    }
}

// 递归
void recursion(int index, int sum){
    if (index == 4){
        if (sum == 24) {
            // 三个步骤
            int a = calculate(arr[0], arr[1], path[0]);
            int b = calculate(a, arr[2], path[1]);
            int c = calculate(b, arr[3], path[2]);
            if (a == -1000 || b == -1000 || c == -1000 || c != 24) return;

            if (arr[1] > arr[0]) printf("%d%c%d=%d\n", arr[1], path[0], arr[0], a);
            else printf("%d%c%d=%d\n", arr[0], path[0], arr[1], a);
            if (arr[2] > a) printf("%d%c%d=%d\n", arr[2], path[1], a, b);
            else printf("%d%c%d=%d\n", a, path[1], arr[2], b);
            if (arr[3] > b) printf("%d%c%d=%d\n", arr[3], path[2], b, c);
            else printf("%d%c%d=%d\n", b, path[2], arr[3], c);

            exit(0);
        } else special();  // 答案进行特判
        return;
    }
    {
        path.push_back('+');
        recursion(index+1, sum + arr[index]);
        path.pop_back();

        if (sum >= arr[index]){
            path.push_back('-');
            recursion(index+1, sum - arr[index]);
            path.pop_back();
        }

        path.push_back('*');
        recursion(index+1, sum * arr[index]);
        path.pop_back();

        if (arr[index] != 0 && sum % arr[index] == 0 && sum > arr[index]){
            path.push_back('/');
            recursion(index+1, sum / arr[index]);
            path.pop_back();
        }
    }
    return;
}

// 递归版本全排列
void permutation(int index){
    // 终止条件
    if (index == 4){
        recursion(1, arr[0]);
    }
    // 遍历每一个元素
    for (int i=index; i<=3; i++){
        // 不断的进行交换
        swap(arr[index], arr[i]);
        permutation(index+1);
        swap(arr[index], arr[i]);
    }
    return; 
}


int main(){
    for (int i=0; i<4; i++){
        cin >> arr[i];
    }
    permutation(0);
    cout << "No answer!" << endl;
    return 0;
}