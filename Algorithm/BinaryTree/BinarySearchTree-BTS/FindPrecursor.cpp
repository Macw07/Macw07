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

int findPredecessor(int pos, int value, int ans){
    if (tree[pos].value >= value){
        if (tree[pos].left_child == 0) return ans;
        return findPredecessor(tree[pos].left_child, value, ans);
    } else{
        if (tree[pos].right_child == 0) return tree[pos].value;
        return findPredecessor(tree[pos].right_child, value, ans);
    }
    return -1;
}

int findSuccessor(int pos, int value, int ans){
    if (tree[pos].value <= value){
        if (tree[pos].right_child == 0) return ans;
        return findSuccessor(tree[pos].right_child, value, ans);
    } else{
        if (tree[pos].left_child == 0) return tree[pos].value;
        return findPredecessor(tree[pos].left_child, value, ans);
    }

    return -1;
}

int findValue(int pos, int value){
    if (pos == 0) return 0;
    if (value == tree[pos].value) return tree[tree[pos].left_child].size;
    if (value < tree[pos].value) return findValue(tree[pos].left_child, value);
    return findValue(tree[pos].right_child, value) + tree[tree[pos].left_child].size; + tree[pos].count_value;
}

int main(){
    cin >> q;
    while(q--){
        cin >> t >> x;
        if (t == 2) cout << findValue(1, x) << endl;
        else if (t == 3) cout << findPredecessor(1, x, -2147483647) << endl;
        else if (t == 4) cout << findPredecessor(1, x, 2147483647) << endl;
        else if (t == 5){
            if (count_node == 0){
                count_node += 1;
                tree[count_node].value = x;
                tree[count_node].size = 1;
                tree[count_node].count_value = 1;
            }  else add(1, x);
        }
    }
    return 0;
}
