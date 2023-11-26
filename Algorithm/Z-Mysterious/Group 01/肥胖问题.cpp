#include <iostream>
using namespace std;

int main(){
    double weight, height;
    cin >> weight >> height;
    double bmi = weight/(height*height);
    if (bmi < 18.5){
        printf("Underweight");
    } else if(bmi >= 18.5 && bmi<24){
        printf("Normal");
    } else{
        cout << bmi << endl;
        printf("Overweight");
    }
    return 0;
}