#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n, m, k, l, d;
int x, y, p, q;
map<int, int> vertical;
map<int, int> horizontal;
struct dimension{
    int coordinate;
    int times;
};
int vp = 1, hp = 1, vp_ = 1, hp_ = 1;
dimension vertical_[2005], horizontal_[2005];
int vertical__[2005], horizontal__[2005];

inline bool cmp(dimension a, dimension b) {
    if (a.times != b.times){
        return a.times > b.times;
    }
    return a.coordinate < b.coordinate;
}

int main(){
    scanf("%d %d %d %d %d", &n, &m, &k, &l, &d);
    for (int i=1; i<=d; i++){
        scanf("%d %d %d %d", &x, &y, &p, &q);
        if (x == p) vertical[min(y, q)] += 1; 
        else horizontal[min(x, p)] += 1;
    }
    map<int, int>::iterator it;
    for (it = vertical.begin(); it != vertical.end(); it++) 
        vertical_[vp++] = (dimension){it->first, it->second};
    for (it = horizontal.begin(); it != horizontal.end(); it++) 
        horizontal_[hp++] = (dimension){it->first, it->second};

    sort(vertical_+1, vertical_+vp, cmp); 
    sort(horizontal_+1, horizontal_+hp, cmp);

    for (int i=1; i<=min(k, hp-1); i++) horizontal__[hp_++] =  horizontal_[i].coordinate;
    for (int i=1; i<=min(l, vp-1); i++) vertical__[vp_++] =  vertical_[i].coordinate;

    sort(horizontal__+1, horizontal__+min(k, hp-1)+1);
    sort(vertical__+1, vertical__+min(l, vp-1)+1);

    for (int i=1; i<=min(k, hp-1); i++) cout << horizontal__[i] << " ";
    cout << endl;
    for (int i=1; i<=min(l, vp-1); i++) cout << vertical__[i] << " ";
    cout << endl;
    return 0;
}