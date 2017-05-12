#include <iostream>
#include <vector>

using namespace std;
/**
    好吧，据说用vector不是很高效
    参考使用最大堆：http://www.cnblogs.com/grandyang/p/4896673.html
*/
class MedianFinder {
public:
    vector<int> nums;
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++) {
            if (num < nums[i]) break;
        }
        nums.insert(nums.begin() + i, num);
    }

    double findMedian() {
        int n = nums.size();
        int mid = (n - 1) / 2;
        if (n % 2 == 1) {
            return (double)nums[mid];
        }
        else {
            return ((double)nums[mid] + (double)nums[mid + 1]) / 2;
        }
    }
};

/**
    解法二最大堆

    参考：
    本来想用priority_queue<double, vector<double>, greater<double>> large;建一个最小堆large
    但是对于负数，会有问题

*/
class MedianFinder {
public:
    priority_queue<double> small, large;
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();

        if (large.size() > small.size()) {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        else {
            return (small.top() - large.top()) / 2;
        }
    }
};


int main() {
    MedianFinder obj = MedianFinder();
    obj.addNum(1);
    obj.addNum(-4);
    obj.addNum(-3);
    obj.addNum(5);
    double param_2 = obj.findMedian();
    return 0;
}
