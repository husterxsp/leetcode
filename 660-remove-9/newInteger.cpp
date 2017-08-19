/**
    不会，参考网上解答。
    转换为9进制，待思考
*/
class Solution {
public:
    int newInteger(int n) {
        int ret = 0;
        int base = 1;

        while (n > 0) {
            ret += n % 9 * base;
            n /= 9;
            base *= 10;
        }
        return ret;
    }
};
