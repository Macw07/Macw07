#include <iostream>
#include <string>
#include <cstring>

// 我真的是服了这道题了，输入输出数据给反了，也不知道是怎么想的

using namespace std;
string a;//这里用STL的字符串
int main(){
	getline(cin,a); //输入字符串
	for(int i=0;i<a.length();i++){
	    if(a[i]=='Z'){//对这两行代码有疑惑移步代码下的疑问解答第二点
		    a[i]='A';
		}else if(a[i]>='A'&&a[i]<='Z'){//如果这个字母是大写字母
			if(a[i]=='Z'){//并且它是A
				a[i]='A';//那么替代成Z
			}else{
				a[i]++;//用前面的字母替代
			}	
		}else if(a[i]>='a'&&a[i]<='z'){//如果这个字母是小写字母
			if(a[i]=='z'){//如果它是a
				a[i]='a';//替代成z
			}else{
				a[i]++; //否则用前面的字母替代
			}	
		}
	}
	cout<<a;//直接输出
}