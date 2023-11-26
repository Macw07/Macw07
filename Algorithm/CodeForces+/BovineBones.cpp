/* 
[USACO08OCT]Bovine Bones G
Bessie loves board games and role-playing games so she persuaded Farmer John to drive her to the hobby shop where she purchased three dice for rolling. These fair dice have S1, S2, and S3 sides
respectively (2 <= S1 <= 20; 2 <= S2 <= 20; 2 <= S3 <= 40). 
Bessie rolls and rolls and rolls trying to figure out which three-dice sum appears most often.
Given the number of sides on each of the three dice, determine which three-dice sum appears most frequently. If more than one sum can appear most frequently, report the smallest such sum.
POINTS: 70 
*/
#include <iostream>
using namespace std;

int main(){
    // 三个变量S1 S2 S3
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    int arr[500] = {};
    // 所有组合
    for (int i=1; i<=S1; i++){
        for (int j=1; j<=S2; j++){
            for (int k=1; k<=S3; k++){
                // printf("%d %d %d\n", i, j, k);
                arr[i+j+k]++;
            }
        }
    }
    // 桶排序
    int temp, sum=0, temp_sum, temp_index;
    for (int i=0; i<500; i++){
        temp = arr[i];
        temp_sum = 0;
        while (temp){
            temp--;
            temp_sum++;
            // cout << i << " ";
        }
        if (temp_sum>sum){
            sum = temp_sum;
            temp_index = i;
        }
    }
    cout << temp_index << " ";
}