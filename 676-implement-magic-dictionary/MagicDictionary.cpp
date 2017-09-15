class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> myDict;
    MagicDictionary() {

    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        myDict = dict;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < myDict.size(); i++) {
            if (word.size() != myDict[i].size()) continue;

            int k = 0;
            for (int j = 0; j < word.size(); j++) {
                if (word[j] != myDict[i][j]) k++;
                if (k > 1) break;
            }
            if (k == 1) return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
