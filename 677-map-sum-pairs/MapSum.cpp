class MapSum {
public:
    unordered_map<string, int> m;
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        m[key] = val;
    }

    int sum(string prefix) {
        int l = prefix.size(), ret = 0;
        for (auto it : m) {
            string tmp = it.first.substr(0, l);
            if (tmp == prefix) ret += it.second;
        }
        return ret;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
