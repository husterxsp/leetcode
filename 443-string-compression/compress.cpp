class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), ret = 0, index = 0;

        for (int i = 0; i < n;) {
            char c = chars[i];
            int num = 0;
            while (i < n && chars[i] == c) {
                num++;
                i++;
            }

            chars[index++] = c;

            if (num > 1) {
                string tmp = to_string(num);
                for (int j = 0; j < tmp.size(); j++) {
                    chars[index++] = tmp[j];
                }
            }
        }
        return index;
    }
};
