#include <iostream>
#include <vector>

using namespace std;
/**
    一次AC...
*/
static bool compare(pair<int, int>&i, pair<int, int>&j) {
    if (i.first < j.first) return true;
    else if (i.first == j.first) return i.second > j.second;
    else return false;
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), compare);
    int n = people.size();
    for (int i = n - 2; i >= 0; i--) {
        int k = people[i].second;
        int j = i;
        while (k > 0) {
            j++;
            k--;
        }
        people.insert(people.begin() + j + 1, people[i]);
        people.erase(people.begin() + i);
    }
    return people;
}
int main() {
    vector<pair<int, int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    reconstructQueue(people);
    return 0;
}
