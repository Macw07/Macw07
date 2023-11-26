#include <iostream>
using namespace std;

int arr[10005] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int range = 0;
    // 如果range一直是可以的情况下
    for (int i=0; i<=range; i++){
        range = max(range, arr[i]+i);
        if (range > n){
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}

// 方法二：
#include <iostream>
using namespace std;

/*
确定状态：dp[i]表示是否能跳到第i块石头
状态转移：dp[i]=1      满足条件 arr[j]+j>=i 
初始化：dp[1]=1 第1块石头一定能跳到
返回结果：dp[n] 第n块石头的结果 
*/

int arr[1005],dp[1005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){  //2 1 0 1 4
			if(arr[j]+j>=i && dp[j]){
				dp[i]=1;
				break;
			}
		}
	}
	if(dp[n]==1){
		cout<<"true";
	}else{
		cout<<"false";
	}
	return 0;
}