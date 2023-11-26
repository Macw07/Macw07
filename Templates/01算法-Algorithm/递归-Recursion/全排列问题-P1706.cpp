#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[10];

vector<vector<int> > result;
vector<int> path;
bool used[100] = {};

void backtracing(int current, int n){
    if (path.size() == n){
        result.push_back(path);
        return;
    }
    for (int i=1; i<=n; i++){
        if (used[i]==1) continue;
        used[i] = 1;
        path.push_back(i);
        backtracing(i+1, n);
        path.pop_back();
        used[i] = 0;
    }
}

int main(){
    cin >> n;
    backtracing(0, n);
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<n; j++){
            cout << "    " << result[i][j];
        }
        cout << endl;
    }
    return 0;
}