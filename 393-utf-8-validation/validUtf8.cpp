#include <iostream>
#include <vector>

using namespace std;
/**
    这题不是很难，但是需要理解清楚题意，
    一开始没加 if (bytes > 4) return false;
    提交了两次都没通过
*/
bool validUtf8(vector<int>& data) {
    int n = data.size();
    if (n == 0) return true;

    int bytes = 0;
    for (int i = 0; i < n; i++) {
        int first = data[i];
        if (bytes > 0) {
            if ((first & 192) != 128) {
                return false;
            }
            bytes--;
        }
        // 1xxxxxxx
        else if (first & 128) {
            // 不允许出现 10xxxxxx
            if (!(first & 64)) return false;
            while ((first & 128)) {
                bytes++;
                first <<= 1;
            }
            if (bytes > 4) return false;
            bytes--;
        }
    }
    return bytes == 0;
}
int main() {
    vector<int> data = {197, 130, 1};
    cout << validUtf8(data) << endl;
    return 0;
}
