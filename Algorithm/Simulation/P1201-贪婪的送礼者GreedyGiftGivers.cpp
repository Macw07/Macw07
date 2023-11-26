#include <iostream>
using namespace std;

int n;
string name[15];
int currency[15];
string from, to;
int origin, k;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> name[i];
    for (int i=1; i<=n; i++){
        cin >> from;
        cin >> origin >> k;

        int index = -1;
        for (int j=1; j<=n; j++) {
            if (from == name[j]){
                index = j;
                break;
            }
        }

        if (k == 0) {
            currency[index] += origin;
            continue;
        }

        int pre = origin / k;
        currency[index] -= origin;
        currency[index] += origin - pre * k;

        for (int j=1; j<=k; j++){
            cin >> to;
            for (int l=1; l<=n; l++){
                if (name[l] == to){
                    currency[l] += pre;
                    break;
                }
            }
        }
    }

    for (int i=1; i<=n; i++) cout << name[i] << " " << currency[i] << endl;
    return 0;
}