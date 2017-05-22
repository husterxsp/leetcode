#include <iostream>
#include <vector>
#include <string>

using namespace std;
int lengthLongestPath(string input) {
    int ret = 0;
    vector<int> dirs;

    // 解决while循环最后一个字符串的问题
    input += '\n';
    int len = input.size();

    int start = 0, end = 0;
    bool isFile = false;
    while (end < len) {
        if (input[end] == '\n') {
            dirs.push_back(end - start + 1);
            end++;

            if (isFile) {
                int tmp = 0;
                for (int l : dirs) tmp += l;
                ret = max(ret, --tmp);
                isFile = false;
            }

            // i 表示层数
            int i = 0;
            while (input[end] == '\t') {
                end++;
                i++;
            }

            dirs.erase(dirs.begin() + i, dirs.end());
            start = end;
        }
        else {
            if (input[end] == '.') isFile = true;
            end++;
        }
    }
    return ret;
}
/*
 dir
     \n\tsubdir1
        \n\t\tfile1.ext
        \n\t\tsubsubdir1
     \n\tsubdir2
        \n\t\tsubsubdir2
            \n\t\t\tfile2.ext
 */
int main() {
    cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    return 0;
}
