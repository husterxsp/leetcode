#include <iostream>
#include <vector>
#include <queue>
#include <Map>
#include <cmath>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
// 解法一：利用排列组合公式，乘法会溢出，无法AC
vector<int> getRow(int rowIndex) {
    vector<int> ret;
    ret.push_back(1);
    if(rowIndex == 0) return ret;
    for(int i=1;i<rowIndex;i++){
        ret.push_back(ret[i-1]*(rowIndex-i+1)/i);
    }
    ret.push_back(1);
    return ret;
}
// 解法二：滚动数组
vector<int> getRow(int rowIndex) {
    vector<int> ret(1, 1);
    if(rowIndex == 0) return ret;
    for(int i=1;i<=rowIndex;i++){
        int prev = 1;
        for(int j=1;j<i;j++){
            int tmp = ret[j];
            ret[j] = prev + tmp;
            prev = tmp;
        }
        ret.push_back(1);
    }
    return ret;
}
int main(){
    getRow(5);
    return 0;
}
