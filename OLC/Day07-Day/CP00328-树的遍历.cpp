#include <iostream>
#include <cstring>
using namespace std;

int n, a, b, c;

struct node{
    int left;
    int right;
} tree[500];

void preorder(int k){
    if (k == 0) return ;
    cout << k << " ";
    preorder(tree[k].left);
    preorder(tree[k].right);
    return ;
}

void inorder(int k){
    if (k == 0) return ;
    inorder(tree[k].left);
    cout << k << " ";
    inorder(tree[k].right);
    return ;
}

void postorder(int k){
    if (k == 0) return ;
    postorder(tree[k].left);
    postorder(tree[k].right);
    cout << k << " ";
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a >> b >> c;
        tree[a].left = b;
        tree[a].right = c;
    }

    preorder(1); cout << endl;
    inorder(1); cout << endl;
    postorder(1); cout << endl;


    return 0;   
}