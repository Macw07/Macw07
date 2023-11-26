/* 已知一个已经从小到大排序的数组，这个数组的一个平台（Plateau）就是连续的一串值相同的元素，
并且这一串元素不能再延伸。例如，在 1，2，2，3，3，3，4，5，5，6中1，2-2，3-3-3，4，5-5，6都是平台。
试编写一个程序，接收一个数组，把这个数组最长的平台找出来。在上面的例子中3-3-3就是最长的平台。 */

#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int num, max_length = 0, temp = 1;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> arr[i];
    }
    for (int i=0; i<num-1; i++){
        if (arr[i] == arr[i+1]){
            temp += 1;
        } else {
            if (temp>max_length){
                max_length = temp;
            }
            temp = 1;
        }     
    }
    if (temp>max_length){
            max_length = temp;
    }
    cout << max_length << endl;
}