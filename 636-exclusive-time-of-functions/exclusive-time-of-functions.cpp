/**
    先格式一下logs
    levelMap：用来保存递归中的其它函数的执行时间
    curLevel：表示当前进入的层级

*/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int len = logs.size();
        vector<vector<int>> formatedLogs(len);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < logs[i].size(); j++) {
                if (logs[i][j] == ':') {
                    formatedLogs[i].push_back(stoi(logs[i].substr(0, j)));
                    if (logs[i][j + 1] == 's') {
                        formatedLogs[i].push_back(0);
                        formatedLogs[i].push_back(stoi(logs[i].substr(j + 7)));
                    }
                    else {
                        formatedLogs[i].push_back(1);
                        formatedLogs[i].push_back(stoi(logs[i].substr(j + 5)));
                    }
                    break;
                }
            }
        }
        vector<int> ret(n);
        map<int, int> levelMap;
        stack<int> myStack;
        int curLevel = 0;

        for (int i = 0; i < len; i++) {
            if (formatedLogs[i][1] == 0) {
                myStack.push(formatedLogs[i][2]);
                curLevel++;
            }
            else {
                int exclusive = formatedLogs[i][2] - myStack.top() + 1;
                myStack.pop();

                levelMap[curLevel] += exclusive;

                if (levelMap[curLevel + 1] != 0) {
                    exclusive -= levelMap[curLevel + 1];
                    levelMap[curLevel + 1] = 0;
                }
                ret[formatedLogs[i][0]] += exclusive;

                curLevel--;
            }
        }
        return ret;
    }
};
