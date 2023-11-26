#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
};

int main(){
    // 链表的声明本质上其实是对结构体进行声明,
    // 比较特殊的一点是数据空间不能开辟到栈区内,只能开辟到堆区(也就是 new 一个)
    ListNode *head = new ListNode;
    ListNode *head2 = new ListNode;
    // 首先我们使用 head01->val 初始化当前节点的数据内容;
    // 然后我们使用 head01->next 指向下一个节点,由于目前没有连接下一个节点,
    // 所以我们指向空(在 C++ 中使用 nullptr 代表空指针,NULL 代表空值)
    head -> data = 100;
    head -> next = nullptr;
    cout << head -> data << endl;
    head -> next = head2;
    return 0;
}