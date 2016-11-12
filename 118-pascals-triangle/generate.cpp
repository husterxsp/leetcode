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
// 循环中重复声明了向量，但是更高效的是用循环数组？
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    if(numRows <= 0){
        return ret;
    }
    ret.push_back({1});
    if(numRows == 1) {
        return ret;
    }
    ret.push_back({1, 1});
    for(int i=2;i<numRows;i++){
        vector<int> line;
        line.push_back(1);
        for(int j=1;j<i;j++){
            line.push_back(ret[i-1][j]+ret[i-1][j-1]);
        }
        line.push_back(1);
        ret.push_back(line);
    }
    return ret;
}

int main(){
    generate(5);
    return 0;
}
