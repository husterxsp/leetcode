#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> ret = {0};
    if(n <= 0) {
        return ret;
    }
    vector<int> tmp;
    for(int i=0;i<n;i++) {
        tmp.clear();
        tmp.insert(tmp.begin(), ret.begin(), ret.end());
        reverse(tmp.begin(), tmp.end());
        for(int j=0;j<tmp.size();j++) {
            tmp[j] += 1<<i;
        }
        ret.insert(ret.end(), tmp.begin(), tmp.end());
    }
    return ret;
}

int main() {
    grayCode(0);
    return 0;
}
