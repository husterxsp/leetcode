#include <iostream>
#include <vector>
#include <unordered_map>

/*
不会，参考网上解法
set 没法常数时间随机取一个元素？
数组删除元素不是常数时间的！
*/
using namespace std;
class RandomizedSet {
private:
    vector<int> eleVector;
    unordered_map<int, int> eleMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (eleMap.find(val) != eleMap.end()) return false;
        eleVector.push_back(val);
        eleMap[val] = eleVector.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (eleMap.find(val) == eleMap.end()) return false;

        eleVector[eleMap[val]] = eleVector.back();
        eleMap[eleVector.back()] = eleMap[val];

        eleVector.pop_back();
        eleMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return eleVector[rand() % eleVector.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
int main() {
    RandomizedSet obj = RandomizedSet();
    bool param_1 = obj.insert(1);
    bool param_2 = obj.remove(2);
    int param_3 = obj.getRandom();
    return 0;
}
