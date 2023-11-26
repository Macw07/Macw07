#include <iostream>
#include <list>
using namespace std;

struct node{
    int data;
    node *previous;
    node *next;
};

void push_back(int data, node *&tail){
    node *temp = new node;
    temp->data = data;
    temp->previous = tail;
    temp->next = nullptr;
    tail = temp;
}
int main(){
    // 创建头和尾
    node *head, *tail;
    head = new node;  // 将内存开辟到堆里面
    head->previous = nullptr;
    head->next = nullptr;
    tail = head;
    // Main
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int t;
        cin >> t;
        push_back(t, tail);
    }
    node *p = tail;
    for (int i=0; i<n; i++){
        if (p->previous != nullptr){
            cout << p->data << " ";
            p = p->previous;
        }
    }
    return 0;
}