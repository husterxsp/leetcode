#include <iostream>
#include <vector>

using namespace std;
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();
    if (!n) return 0;

    int start = 0, end = 0, ret = 0;
    for (int i = 0; i < n; i++) {
        if (end > timeSeries[i]) {
            end = timeSeries[i] + duration;
        }
        else {
            ret += end - start;
            start = timeSeries[i];
            end = start + duration;
        }
    }
    ret += end - start;
    return ret;
}

int main(){
    vector<int> timeSeries{1,4};
    cout << findPoisonedDuration(timeSeries, 2) << endl;
    return 0;
}
