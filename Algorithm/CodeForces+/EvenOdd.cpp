/* # [USACO09OCT]Even? Odd? G
Bessie's cruel second grade teacher has assigned a list of N (1 <= N <= 100) positive integers I (1 <= I <= 10^60) for which Bessie must determine their parity (explained in second grade as 'Even... or odd?'). Bessie is overwhelmed by the size of the list and by the size of the numbers. After all, she only learned to count recently.
Write a program to read in the N integers and print 'even' on a single line for even numbers and likewise 'odd' for odd numbers.
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    string j;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> j;
        if (j[j.size()-1]%2==0){
            cout << "even" << endl;
        } else{
            cout << "odd" << endl;
        }
    }
}