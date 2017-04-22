#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
int hIndex(vector<int>& citations) {
    int index = 0;
    for (int i = citations.size() - 1; i >= 0; i--, index++) {
        if (index >= citations[i]) return index;
    }
    return citations.size();
}

int main () {
    vector<int> citations = {0};
    cout << hIndex(citations) << endl;
    return 0;
}
