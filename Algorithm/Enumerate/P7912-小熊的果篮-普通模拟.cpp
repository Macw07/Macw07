#include <iostream>
#include <vector>
using namespace std;

int n, k, current;
struct node{
    int id;
    int type;
};
int a1, a2;
node arr1[200005];
node arr2[200005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d", &m);
        arr1[a1++] = (node){i, m};
    }
    while(true){
        if (k == 0){
            if (a1 == 0) break;
            current = arr1[0].type;
            for (int i=0; i<a1; i++){
                if (arr1[i].type == current){
                    printf("%d ", arr1[i].id);
                    current ^= 1;
                } else{
                    arr2[a2++] = (node){arr1[i].id, arr1[i].type};
                }
            }
            a1 = 0;
            printf("\n");
        } else{
            if (a2 == 0) break;
            current = arr2[0].type;
            for (int i=0; i<a2; i++){
                if (arr2[i].type == current){
                    printf("%d ", arr2[i].id);
                    current ^= 1;
                } else{
                    arr1[a1++] = (node){arr2[i].id, arr2[i].type};
                }
            }
            a2 = 0;
            printf("\n");
        }
        k ^= 1;
    }
    return 0;
}