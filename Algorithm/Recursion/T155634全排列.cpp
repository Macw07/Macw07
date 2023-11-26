#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<vector<int> > result;
bool visited[105] = {};

void permutation(int current, int n){
    // 如果数组已经放满了（达到递归停止条件）
    if (current == n){
        result.push_back(arr);
        return;
    }
    // 遍历树形结构的当前层级
    for (int i=1; i<=n; i++){
        if (visited[i] == 1) continue;  // 如果已经被使用过了，就不需要再使用了。
        // 如果没有被使用，就标记为使用并进行递归。
        visited[i] = 1;
        arr.push_back(i);  // 将数字存入。
        permutation(current+1, n);
        // 撤销使用。
        arr.pop_back();
        visited[i] = 0;
    }

}

int main(){
    int n;
    cin >> n;
    permutation(0, n);
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}