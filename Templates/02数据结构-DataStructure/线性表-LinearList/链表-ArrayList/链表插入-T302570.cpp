#include <iostream>
#include <list>
using namespace std;

struct node{
    int data;
    node *next;
};

void push_back(int data, node *&tail){
    node *temp = new node;
    temp->data = data;
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
}

int main(){
    // 创建链表头
    node *head, *tail;
    head = new node;
    head->next = nullptr;
    tail = head;
    // 循环读入
    int n, q, m;
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        push_back(t, tail);
    }
    cin >> q >> m;
    node *p = head;
    while(p->next != nullptr){
        cout << p->next->data << " ";
        if (p->next->data == q){
            cout << m << " ";
        }
        p = p->next;
    }
    return 0;
}