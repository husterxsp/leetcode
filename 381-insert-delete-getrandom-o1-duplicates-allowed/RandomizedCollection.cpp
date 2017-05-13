#include <iostream>
#include <vector>
#include <map>

using namespace std;

class RandomizedCollection {
private:
    vector<int> eleVector;
    multimap<int, int> eleMap;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = eleMap.find(val) == eleMap.end();
        eleVector.push_back(val);
        eleMap.insert({val, eleVector.size() - 1});
        return ret;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool ret = eleMap.find(val) != eleMap.end();
        if (ret) {
            auto itor = eleMap.find(val);
            int index = itor->second;
            int last = eleVector.back();

            eleVector[index] = last;

            /*
                和380类似，主要修改的是以下这部分
                修改了map的second后，没有再排序了
            */
            auto range = eleMap.equal_range(last);
            for (auto i = range.first; i != range.second; i++) {
                if (i->second == eleVector.size() - 1) {
                    i->second = index;
                    break;
                }
            }

            eleVector.pop_back();
            eleMap.erase(itor);
        }

        return ret;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return eleVector[rand() % eleVector.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main() {
    RandomizedCollection obj = RandomizedCollection();
    cout << obj.insert(1) << endl;
    cout << obj.insert(1) << endl;
    cout << obj.insert(2) << endl;
    cout << obj.insert(1) << endl;
    cout << obj.insert(2) << endl;
    cout << obj.insert(2) << endl;

    cout << obj.remove(1) << endl;
    cout << obj.remove(2) << endl;
    cout << obj.remove(2) << endl;
    cout << obj.remove(2) << endl;

    int i = 0;
    while (i++ < 10) {
        cout << obj.getRandom() << endl;
    }

    return 0;
}
