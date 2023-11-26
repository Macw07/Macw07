#include<iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;
stack<int> s;

int main(){
	string a;
	getline(cin,a);
    int len = a.size()-1;
	for(int i=len;i>=0;i--){
		int sum=0,k=0;
        // 数字反转
		while(a[i]>='0'&&a[i]<='9'){
			sum+=(a[i]-'0')*pow(10,k++); 
			i--;
		}
		if(sum!=0) s.push(sum);	
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			int num1=s.top();
			s.pop();
			int num2=s.top();
			s.pop();
			if(a[i]=='+') s.push(num1+num2);
			else if(a[i]=='-') s.push(num1-num2);
			else if(a[i]=='*') s.push(num1*num2);
			else if(a[i]=='/') s.push(num1/num2);		
		}
	} 
	cout<<s.top();
	return 0;
}

// #include <iostream>
// #include <stack>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// stack<int> stk;

// int convert(string s){
//     int n=0, len=s.size();
//     for (int i=len-1; i>=0; i--){
//         n = n*10 + s[i]-'0';
//     }
//     return n;
// }
// string arr[1000005] = {};

// int main(){
//     string s;
//     getline(cin, s);
//     int len=s.size(), k=0, count=0;
//     reverse(s.begin(), s.end());
//     for (int i=0; i<len; i++){
//         if (s[i] >= '0' && s[i] <= '9'){
//             count++;
//             arr[k] += s[i];
//         } else if (s[i] == ' '){
//             if (count > 0){
//                 // cout << convert(arr[k++]) << endl;
//                 stk.push(convert(arr[k++]));
//                 count = 0;
//             }
//         } else{
//             if (count > 0){
//                 // cout << convert(arr[k++]) << endl;
//                 stk.push(convert(arr[k++]));
//                 count = 0;
//             }
//             int a=0, b=0;
//             if (stk.size() >= 2){
//                 a = stk.top();
//                 stk.pop();
//                 b = stk.top();
//                 stk.pop();
//             }
//             // cout << a << s[i] << b << endl;
//             if (a == 0 || b == 0) continue;
//             if (s[i] == '+') stk.push(a+b);
//             else if (s[i] == '-') stk.push(a-b);
//             else if (s[i] == '*') stk.push(a*b);
//             else if (s[i] == '/') stk.push(a/b);
//         }
//     }
//     if (!stk.empty()){
//         cout << stk.top();
//     }
//     return 0;
// }