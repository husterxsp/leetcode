#include <iostream>
#include <vector>

using namespace std;
/**
    这题标easy真是不合适。。搞了好久md。。
    一开始尝试用两个数组分别存储小时和分钟，但是有各种问题。。
*/
void search(vector<string>& ret, vector<int>& time, int tIndex, int num) {
    int h = 0, m = 0;
    for (int i = 0; i < 10; i++) {
        if (i < 4) {
            h = h * 2 + time[i];
        }
        else {
            m = m * 2 + time[i];
        }
    }

    if (10 - tIndex < num || h > 11 || m > 59) return;

    if (num == 0) {
        string tmp = to_string(m);
        if (tmp.size() == 1) tmp = "0" + tmp;
        tmp = to_string(h) + ":" + tmp;
        ret.push_back(tmp);
        return;
    }

    for (int i = tIndex; i < 10; i++) {
        time[i] = 1;
        search(ret, time, i + 1, num - 1);
        time[i] = 0;
    }
}

vector<string> readBinaryWatch(int num) {
    vector<string> ret;
    vector<int> time(10, 0);
    search(ret, time, 0, num);
    return ret;
}

int main() {
    readBinaryWatch(2);
    return 0;
}
