/**
    解法一：算是暴力解
*/
#include <iostream>
#include <vector>

using namespace std;
class MyCalendar {
public:
    vector<vector<int>> arr{{INT_MIN, INT_MIN}, {INT_MAX, INT_MAX}};
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (int i = 0; i < arr.size(); i++) {
            if (start >= arr[i][1] && end <= arr[i + 1][0]) {
                // 这个地方的合并区间对AC时间完全没影响。。。
                if (start == arr[i][1] && end == arr[i + 1][0]) {
                    arr[i][1] = arr[i + 1][0];
                    arr.erase(arr.begin() + i + 1);
                }
                else if (start == arr[i][1]) {
                    arr[i][1] = end;
                }
                else if (end == arr[i + 1][0]) {
                    arr[i + 1][0] = start;
                }
                else {
                    arr.insert(arr.begin() + i + 1, {start, end});
                }
                return true;
            }
            else if ((arr[i][1] > start && arr[i][1] < end) ||
                     (arr[i][0] > start && arr[i][0] < end)) {
                return false;
            }
        }
        return false;
    }
};
int main() {
    MyCalendar obj = MyCalendar();
    cout << obj.book(20,29) << endl;
    cout << obj.book(44,50) << endl;
    cout << obj.book(1,7) << endl;
    cout << obj.book(14,20) << endl;
    cout << obj.book(36,42) << endl;
    cout << obj.book(45,50) << endl;
    cout << obj.book(47,50) << endl;
    return 0;
}

/**
    解法二：用map
*/

class MyCalendar {
public:
    map<int, int> myMap;
    MyCalendar() {
        myMap[INT_MIN] = INT_MIN;
        myMap[INT_MAX] = INT_MAX;
    }

    bool book(int start, int end) {

        auto lowerKey = myMap.lower_bound(start);
        if (lowerKey->first == start) return false;
        if (--lowerKey != myMap.end() && lowerKey->second > start) return false;

        auto upperKey = myMap.upper_bound(start);
        if (upperKey != myMap.end() && upperKey->first < end) return false;

        myMap[start] = end;
        return true;
    }
};
