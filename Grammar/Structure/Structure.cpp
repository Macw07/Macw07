#include <iostream>
#include <cstring>
using namespace std;

// 声明一个结构体类型 Books
struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

int main() {
    Books Book1; // 定义结构体类型 Books 的变量 Book1
    Books Book2; // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy(Book1.title, "C++");
    strcpy(Book1.author, "Marco");
    strcpy(Book1.subject, "Language");
    Book1.book_id = 12345;

    // Book2 详述
    strcpy(Book2.title, "CSS");
    strcpy(Book2.author, "Marco");
    strcpy(Book2.subject, "Language");
    Book2.book_id = 123456;

    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title <<endl;
    cout << "第一本书作者 : " << Book1.author <<endl;
    cout << "第一本书类目 : " << Book1.subject <<endl;
    cout << "第一本书 ID : " << Book1.book_id <<endl;
 
   // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title <<endl;
    cout << "第二本书作者 : " << Book2.author <<endl;
    cout << "第二本书类目 : " << Book2.subject <<endl;
    cout << "第二本书 ID : " << Book2.book_id <<endl;
 
    return 0;
}