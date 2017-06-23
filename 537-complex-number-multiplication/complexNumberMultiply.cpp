class Solution {
public:
    vector<int> splitNumber(string a) {
        vector<int> ret(2, 0);
        int i = 0;
        while (i < a.size())
            if (a[i] == '+') break;
            else i++;

        ret[0] = stoi(a.substr(0, i));
        ret[1] = stoi(a.substr(i + 1, a.size() - i - 2));
        return ret;
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> num1 = splitNumber(a);
        vector<int> num2 = splitNumber(b);

        int real = 0, complex = 0;
        real = num1[0] * num2[0] - num1[1] * num2[1];
        complex = num1[0] * num2[1] + num1[1] * num2[0];

        string ret = to_string(real) + "+" + to_string(complex) + "i";
        return ret;
    }
};
