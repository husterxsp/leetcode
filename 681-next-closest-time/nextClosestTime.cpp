class Solution {
public:
    string getTime(vector<int> timeVec) {
        string ret = "";
        for (int i = 0; i < 4; i++) {
            ret += timeVec[i] + '0';
            if (i == 1) ret += ':';
        }
        return ret;
    }
    bool checkValid(vector<int> timeVec) {
        int hour = timeVec[0] * 10 + timeVec[1];
        int minute = timeVec[2] * 10 + timeVec[3];

        return hour < 24 && minute < 60;
    }
    string nextClosestTime(string time) {
        int n = time.size(), splitPos = 0;
        vector<int> timeVec;
        for (int i = 0; i < n; i++) {
            if (time[i] == ':') splitPos = i;
            else {
                timeVec.push_back(time[i] - '0');
            }
        }
        if (timeVec.size() < 4) {
            if (timeVec.size() < 3) {
                timeVec.insert(timeVec.begin(), 0);
                timeVec.insert(timeVec.begin() + 2, 0);
            }
            else if (splitPos == 1) timeVec.insert(timeVec.begin(), 0);
            else if (splitPos == 2) timeVec.insert(timeVec.begin() + 2, 0);
        }

        set<int> mySet{timeVec.begin(), timeVec.end()};
        for (int i = 3; i >= 0; i--) {
            for (auto it : mySet) {
                if (it > timeVec[i]) {
                    int tmp = timeVec[i];
                    timeVec[i] = it;
                    if (checkValid(timeVec)) return getTime(timeVec);
                    else {
                        timeVec[i] = tmp;
                        continue;
                    }
                }
            }
            timeVec[i] = *mySet.begin();
        }
        return getTime(timeVec);
    }
};
