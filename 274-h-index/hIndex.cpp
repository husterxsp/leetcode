#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
int hIndex(vector<int>& citations) {

    sort(citations.begin(), citations.end(), [](const int a, const int b) {return a > b; });

//    sort(citations.begin(), citations.end(), greater<int>());
    for (int i = 0; i < citations.size(); i++) {
        if (i >= citations[i]) return i;
    }
    return citations.size();
}

int main () {
    vector<int> citations = {21,100,0};
    cout << hIndex(citations) << endl;
    return 0;
}
