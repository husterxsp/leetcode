/**
    思路：排好序后，对于某一个人，>=他的高度的人有几个，在数组中就往后移动几位。
*/
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first || (a.first == b.first && a.second > b.second);
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    int n = people.size();
    for (int i = n - 1; i >= 0; i--) {
        people.insert(people.begin() + i + people[i].second + 1, people[i]);
        people.erase(people.begin() + i);
    }
    return people;
}
int main() {
    vector<pair<int, int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    reconstructQueue(people);
    return 0;
}
