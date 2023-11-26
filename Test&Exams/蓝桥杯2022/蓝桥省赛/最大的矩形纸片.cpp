#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

struct node{
	ll x,t;//记录当前矩形的下标和矩形的高度 
};
stack<node> stk;//维护一个单调递减的栈，可以快速找到左边第一个比当前元素小，右边第一个比当前元素小 

int main(){
	int n;
	cin>>n;
	stk.push((node){0,0});//方便计算，先入栈第一个 
	ll ans=0;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		/*
		如果当前矩形比栈顶元素要小，那就出栈，同时计算下出栈的矩形的最大面积，面积计算=右边第一个比出栈的矩形小的下标，就是i
		减去比出栈的矩形大的，就是新的栈顶元素，就是矩形的长，再乘以高，就是出栈的矩形的面积 
		*/
		while(stk.size()>1&&t<stk.top().t){
			node cur=stk.top();
			stk.pop();
			ans=max(ans,cur.t*(i-stk.top().x-1));
		}
		stk.push((node){i,t});//大的直接入栈，因为比前面大，是可以往左衍生组成面积的 
	}
	while(stk.size()>1){//表示都是递减的，出栈一个，算一个 
		node cur=stk.top();
		stk.pop();
		ans=max(ans,cur.t*(n-stk.top().x));
	}
	cout<<ans;
	return 0;
} 
