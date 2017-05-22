#include <iostream>
#include <vector>

using namespace std;
string decodeString(string s) {
    vector<string> strStack;
    vector<int> intStack;
    int n = s.size();
    int num = 0;
    string str = "";

    for (int i = 0; i < n; i++) {
        char c = s[i];
        // 字符串
        if (c >= 'a' && c <= 'z' || c > 'A' && c < 'Z') {
            str += c;
        }
        else if (str != "") {
            strStack.push_back(str);
            str = "";
        }

        // 数字
        if (c >= '0' && c <= '9') {
            num += num * 10 + c - '0';
        }

        if (c == '[') {
            strStack.push_back(c);
            num = num != 0 ? num : 1;
            intStack.push_back(num);
            num = 0;
        }
        else if (c == ']') {
            string tmp = "";
            while (strStack.back() != '[') {
                tmp += strStack.back();
                strStack.pop_back();
            }

            int repeat = intStack.back();
            intStack.pop_back();
            while (repeat-- > 0) {
                tmp += tmp;
            }

            strStack.push_back(str);
        }
    }
    if (str != "") strStack.push_back(str);

    string ret = "";
    while (!strStack.empty()) {
        str += strStack.back();
        strStack.pop_back();
    }
}

int main() {
    cout << decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}
