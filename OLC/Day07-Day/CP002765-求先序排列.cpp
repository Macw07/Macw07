#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 求先序遍历
void preorder(string in, string post){
    if (in.size()){
        char lst = post[post.size()-1];
        cout << lst;
        int k = in.find(lst);
        preorder(in.substr(0, k), post.substr(0, k));
        preorder(in.substr(k+1), post.substr(k, in.size()-1-k));
    }
    return ;
}

int main(){
    string in, post;
    cin >> in >> post;
    preorder(in, post);
    return 0;
}