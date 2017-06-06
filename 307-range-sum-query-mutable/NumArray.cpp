/**
    参考 <<算法竞赛入门经典-训练指南>>
    二叉索引树（树状数组）（Binary Indexed Tree）
    需要维护两个数组A, C
    A: 即需要累加的数组，但是第一个元素不计算在内
    C: C(i) = A(i - lowbit(i) + 1) + A(i - lowbit(i) + 2) + ... + A(i)

    计算lowbit： x & -x ,由于计算机按补码存储，所以 -x 实际是 x 按位取反 再加 1

    计算前缀和S(i)：顺着BIT树节点i往左上走
    修改A(i)：从C(i) 往右上走

    预处理：清空A,C数组，实行n次update操作，时间复杂度O(nlogn)

*/
class NumArray {
private:
    vector<int> c;
    vector<int> a;
public:
    NumArray(vector<int> nums) {
        c.resize(nums.size() + 1);
        a.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }

    int lowbit(int i) {
        return i & -i;
    }

    void update(int i, int val) {
        // 原始数组是从0开始，bit树对应的数组从索引1开始，所以此处加1
        i++;
        int diff = val - a[i];
        // 先更新数组a, 便于下次更新时知道diff
        a[i] = val;
        // 再更新数组c
        while (i < c.size()) {
            c[i] += diff;
            i += lowbit(i);
        }

    }

    int sumRange(int i, int j) {
        return sum(j + 1) - sum(i);
    }

    int sum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += c[i];
            i -= lowbit(i);
        }
        return ret;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
