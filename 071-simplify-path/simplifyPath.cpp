#include <iostream>
#include <vector>

using namespace std;

// 参考：http://bangbingsyb.blogspot.com/2014/11/leetcode-simplify-path.html

string simplifyPath(string path) {
    string ret, cur;
    vector<string> dirs;

    path.push_back('/');
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
            if (cur.empty()) {
                continue;
            }
            else if (cur == ".") {
                cur.clear();
            }
            else if (cur == "..") {
                if (!dirs.empty()) dirs.pop_back();
                cur.clear();
            }
            else {
                dirs.push_back(cur);
                cur.clear();
            }
        }
        else {
            cur.push_back(path[i]);
        }
    }

    for (int i = 0; i < dirs.size(); i++) {
        ret += "/" + dirs[i];
    }
    return !ret.empty() ? ret : "/";
}

int main()
{
    cout << simplifyPath("/./2312312") << endl;
    return 0;
}
