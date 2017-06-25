class Solution {
public:
    /**
        找规律，统计
        o: one, two, four, zero
        n: one, seven, nine
        e: one, three, five, seven, eight, nine, zero
        t: two, three, eight
        w: two
        h: three, eight
        r: three, four, zero
        f: four, five
        u: four,
        i: five, six, eight, nine
        v: five, seven
        s: six, seven
        x: six,
        g: eight
        z: zero
        zero, one, two, three, four, five, six, seven, eight, nine
    */
    string originalDigits(string s) {
        unordered_map<char, int> myMap;
        for (auto c : s) myMap[c]++;

        string ret = "";
        vector<int> nums(10);
        // 0,2,4,6,8
        nums[0] = myMap['z'];
        nums[2] = myMap['w'];
        nums[4] = myMap['u'];
        nums[6] = myMap['x'];
        nums[8] = myMap['g'];

        nums[1] = myMap['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = myMap['h'] - nums[8];
        nums[5] = myMap['f'] - nums[4];
        nums[7] = myMap['v'] - nums[5];

        // 注意nine中有两个n,所以不能用n来计算。。或者除个2。。
        // nums[9] = myMap['n'] - nums[1] - nums[7];
        nums[9] = myMap['i'] - nums[5] - nums[6] - nums[8];
        for (int i = 0; i < 10; i++) ret.append(nums[i], i + '0');

        return ret;
    }
};
