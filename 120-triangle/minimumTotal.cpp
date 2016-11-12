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
// O(n)空间复杂度，O(n^2)时间复杂度
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    if(n <= 0) return 0;
    vector<int> arr(triangle[n-1].begin(), triangle[n-1].end());
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            arr[j] = triangle[i][j] + min(arr[j], arr[j+1]);
        }
    }
    return arr[0];
}
//
int main(){
    vector<vector<int>> a = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << minimumTotal(a);
    return 0;
}
