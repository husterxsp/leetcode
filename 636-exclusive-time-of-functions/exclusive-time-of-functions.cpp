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
        vector<int> ret(n), level(n);
        unordered_map<int, int> surplus;
        stack<int> myStack;
        for (int i = 0; i < len; i++) {
            if (formatedLogs[i][1] == 0) {
                myStack.push(formatedLogs[i][2]);
                myMap[formatedLogs[i][0]]++;
            }
            else {
                int exclusive = formatedLogs[i][2] - myStack.top() + 1;
                myStack.pop();

                ret[formatedLogs[i][0]] += exclusive - sum;
                sum += exclusive;
            }
            if (myStack.empty()) sum = 0;
        }
        return ret;
    }
};
