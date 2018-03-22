/**
 广搜，参考773
 flag表示是否访问，放在for循环的后面，因为一开始0 就已经访问了，如果放前面判断，直接就退出了
 myset表示是否是终止节点，放前面，因为起始节点可能为终止节点。
 一点问题。为什么一找到目标节点就可以直接退出？最优解？

*/
class Solution {
public:
    bitset<10000> flag;
    struct Node {
        string state;
        int moves;
        Node(string state, int moves)
            :state(state), moves(moves){}
    };

    string move(string s, int i, int dir) {
        s[i] += dir;
        if (s[i] > '9') s[i] = '0';
        else if (s[i] < '0') s[i] = '9';
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> myset(deadends.begin(), deadends.end());

        Node cur = Node("0000", 0);
        flag.set(0);

        queue<Node> myQueue;
        myQueue.push(cur);
        while (!myQueue.empty()) {
            cur  = myQueue.front();
            myQueue.pop();

            if (myset.find(cur.state) != myset.end()) continue;
            if (cur.state == target) return cur.moves;

            for (int i = 0; i < 4; i++) {
                for (int j = -1; j < 2; j += 2) {
                    Node tmp = cur;
                    tmp.moves++;
                    tmp.state = move(cur.state, i, j);

                    if (flag[stoi(tmp.state)]) continue;
                    flag.set(stoi(tmp.state));
                    myQueue.push(tmp);
                }
            }
        }
        return -1;
    }
};

/**
    双向广搜, 以下参考：https://leetcode.com/problems/open-the-lock/discuss/110230
    一层层地进行扩展。上面的是一个个进行扩展。
*/
class Solution {
public:
    string move(string s, int i, int dir) {
        s[i] += dir;
        if (s[i] > '9') s[i] = '0';
        else if (s[i] < '0') s[i] = '9';
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> q1{"0000"}, q2{target}, vis;
        if (dead.find("0000") != dead.end()) return -1;

        int ret = 0;
        while (!q1.empty() && !q2.empty()) {
            if (q1.size() > q2.size()) swap(q1, q2);

            unordered_set<string> tmpQ;
            for (string str : q1) {
                for (int i = 0; i < 4; i++) {
                    for (int j = -1; j < 2; j += 2) {
                        string tmpStr = move(str, i, j);

                        if (q2.find(tmpStr) != q2.end()) return ret + 1;
                        if (dead.find(tmpStr) != dead.end() || vis.find(tmpStr) != vis.end()) continue;

                        vis.insert(tmpStr);
                        tmpQ.insert(tmpStr);
                    }
                }
            }
            q1 = tmpQ;
            ret++;
        }
        return -1;
    }
};
