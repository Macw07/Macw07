#include<iostream>
#include<cmath>
using namespace std;

int h,r,a;

int main(){
	cin>>h>>r;
	a=20000/(3.14159*r*r*h)+1;
	cout<<a;
	return 0;
}