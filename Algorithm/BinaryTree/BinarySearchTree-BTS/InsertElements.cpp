#include <iostream>
using namespace std;

int q, t, x, count_node;

struct node{
    int value;
    int left_child;
    int right_child;
    int count_value;
    int size;  // 数的大小和自己大小的和。
} tree[100005];

void traverse(int pos){
    cout << tree[pos].value << " ";
    if (tree[pos].left_child) traverse(tree[pos].left_child);
    if (tree[pos].right_child) traverse(tree[pos].right_child);
    return ;
}

void add(int pos, int value){
    tree[pos].size += 1;
    if (tree[pos].value == value){
        tree[pos].count_value += 1;
        return ;
    }
    // 递归左子树
    if (tree[pos].value < value){
        if (tree[pos].left_child) add(tree[pos].left_child, value);
        else {
            count_node += 1;
            tree[count_node].value = value;
            tree[count_node].count_value = tree[count_node].size = 1;
            tree[pos].left_child = count_node;
        }
    }
    // 递归右子树
    if (tree[pos].value > value){
        if (tree[pos].right_child) add(tree[pos].right_child, value);
        else {
            count_node += 1;
            tree[count_node].value = value;
            tree[count_node].size = tree[count_node].count_value = 1;
            tree[pos].right_child = count_node;
        }
    }
    return ;
}

int main(){
    cin >> q;
    while(q--){
        cin >> t >> x;
        if (t == 5){
            if (count_node == 0){
                count_node += 1;
                tree[count_node].value = x;
                tree[count_node].size = 1;
                tree[count_node].count_value = 1;
            }  else add(1, x);
        }
    }
    traverse(1);
    return 0;
}
