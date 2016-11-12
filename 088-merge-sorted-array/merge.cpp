#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 一些诡异的输入，{0}，0，{1,0},1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> ret;
    int k=0, i=0, j=0;
    while (i<m && j<n) {
        if(nums1[i] < nums2[j]){
            ret.push_back(nums1[i++]);
        } else {
            ret.push_back(nums2[j++]);
        }
        k++;
    }
    if(i != m){
        ret.insert(ret.begin()+k, nums1.begin()+i, nums1.begin()+m);
    }
    if(j != n){
        ret.insert(ret.begin()+k, nums2.begin()+j, nums2.begin()+n);
    }

    nums1.erase(nums1.begin(), nums1.end());
    nums1.insert(nums1.begin(), ret.begin(), ret.end());
}

int main()
{
    vector<int> num1 = {2,0};
    vector<int> num2 = {1};
    merge(num1, 1, num2, 1);
    return 0;
}
