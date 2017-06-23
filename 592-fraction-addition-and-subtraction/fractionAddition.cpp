/**
    求最小公倍数（lcm，lowest common multiple），计算
    1. 两数乘积 / 最大公约数
    求最大公约数（gcd，Greatest Common Divisor），约分
    1. 辗转相除法
        ① a%b得余数c
        ② 若c=0，则b即为两数的最大公约数
        ③ 若c≠0，则a=b，b=c，再回去执行①
    2. 更相减损术
*/
class Solution {
public:
    // https://zh.wikipedia.org/wiki/%E6%9C%80%E5%A4%A7%E5%85%AC%E5%9B%A0%E6%95%B8
    int gcd(int a, int b) {
        if (b) while ((a %= b) && (b %= a));
        // 计算到最后可能a=0或者b=0
        return a + b;
    }
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
    pair<int, int> fractionAddition(pair<int, int> a, pair<int, int> b) {
        int LCM = lcm(a.second, b.second);
        pair<int, int> ret;

        ret.first = (LCM / a.second * a.first) + (LCM / b.second * b.first);
        ret.second = LCM;

        int GCD = gcd(abs(ret.first), ret.second);
        ret.first /= GCD;
        ret.second /= GCD;

        return ret;
    }
    string fractionAddition(string expression) {
        deque<pair<int, int>> num;
        string numerator = "", denominator = "";
        bool fraction = false;
        expression += "+";

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '+' || c == '-') {
                if (numerator.length() && denominator.length()) {
                    num.push_back({stoi(numerator), stoi(denominator)});
                    numerator = "";
                    denominator = "";
                }
                numerator += c;
                fraction = false;
            }
            else if (c >= '0' && c <= '9') {
                if (fraction) denominator += c;
                else numerator += c;
            }
            else if (c == '/') fraction = true;
        }
        while (num.size() > 1) {
            num.push_back(fractionAddition(num[0], num[1]));
            num.pop_front();
            num.pop_front();
        }

        if (num.size() == 0) return "0/1";
        return to_string(num[0].first) + "/" + to_string(num[0].second);
    }
};
/**
    更简洁的解法，用istringstream...
    ... 另外不用求最小公倍数，直接乘上分母，最后化简就好。。。
    http://www.cnblogs.com/grandyang/p/6954197.html
*/
