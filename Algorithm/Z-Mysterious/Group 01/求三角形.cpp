#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=n*i+1; j<n*i+n+1; j++){
            if (j<10) printf("0%d", j);
            else printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");
    int count=0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<n-i; j++){
            printf("  ");
        }
        for (int j=0; j<i; j++){
            count++;
            if (count<10) printf("0%d", count);
            else printf("%d", count);
        }
        printf("\n");
    }
    return 0;    
}