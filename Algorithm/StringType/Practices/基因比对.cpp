/* 题目描述
为了获知基因序列在功能和结构上的相似性，经常需要将几条不同序列的 DNA 进行比对，以判断该比对的 DNA 是否具有相关性。
现比对两条长度相同的 DNA 序列。首先定义两条 DNA 序列相同位置的碱基为一个碱基对，如果一个碱基对中的两个碱基相同的话，则称为相同碱基对。接着计算相同碱基对占总碱基对数量的比例，如果该比例大于等于给定阈值时则判定该两条 DNA 序列是相关的，否则不相关。

输入格式
有三行。第一行为一个 [0,1]范围内实数，表示用来判定出两条 DNA 序列是否相关的阈值，随后 2 行是两条DNA 序列（长度不大于 500）。

输出格式
若两条 DNA 序列相关，则输出yes，否则输出no。 */
#include <iostream>
using namespace std;

int main(){
    double same_index;
    string DNA1, DNA2;
    double same=0;

    // same_index = 0.85;
    // DNA1 = "ATCGCCGTAAGTAACGGTTTTAAATAGGCC";
    // DNA2 = "ATCGCCGGAAGTAACGGTCTTAAATAGGBCabc";
    
    std::cin >> same_index;
    std::cin >> DNA1;
    std::cin >> DNA2;
    if (DNA1.size() < DNA2.size()){
        string temp;
        temp = DNA1;
        DNA1 = DNA2;
        DNA2 = temp;
    }
    for (int i=0; i<DNA1.size(); i++){
        if (DNA1[i] == DNA2[i]){
            same++;
        }
    }
    // cout << same << endl;
    // cout << DNA1.size() << endl;
    // cout << same/DNA1.size() << endl;
    // cout << same_index << endl;
    if (same/DNA1.size() > same_index){
        cout << "yes";
    } else {
        cout << "no";
    }
}