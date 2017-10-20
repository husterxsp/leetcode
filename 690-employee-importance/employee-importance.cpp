/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ret = 0, n = employees.size();
        unordered_map<int, Employee*> myMap;

        for (int i = 0; i < n; i++) {
            myMap[employees[i]->id] = employees[i];
        }

        queue<Employee*> subordinatesQue;
        subordinatesQue.push(myMap[id]);

        while (!subordinatesQue.empty()) {
            int sz = subordinatesQue.size();
            for (int i = 0; i < sz; i++) {
                Employee* employee = subordinatesQue.front();
                subordinatesQue.pop();

                for (auto e : employee->subordinates) subordinatesQue.push(myMap[e]);

                ret += employee->importance;
            }
        }
        return ret;
    }
};
