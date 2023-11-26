// 小云和朋友们去爬香山，为美丽的景色所陶醉，想合影留念。如果他们站成一排，男生全部在左（从拍照者的角度），并按照从矮到高的顺序从左到右排，
// 女生全部在右，并按照从高到矮的顺序从左到右排，请问他们合影的效果是什么样的（所有人的身高都不同）？

#include <iostream>
using namespace std;

string gender[45] = {};
float height[45] = {};

int main(){
    int num;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> gender[i] >> height[i];
    }
    for (int i=0; i<num-1; i++){
        for (int j=0; j<num-i-1; j++){
            if (gender[j]=="female" && gender[j+1]=="male"){
                swap(gender[j], gender[j+1]);
                swap(height[j], height[j+1]);
            }
            if (gender[j]=="male" && height[j] > height[j+1]){
                swap(gender[j], gender[j+1]);
                swap(height[j], height[j+1]);
            }
            if (gender[j]=="female" && height[j] < height[j+1]){
                swap(gender[j], gender[j+1]);
                swap(height[j], height[j+1]);
            }
        }
    }
    for (int i=0; i<num; i++){
        printf("%.2f ", height[i]);
    }
}