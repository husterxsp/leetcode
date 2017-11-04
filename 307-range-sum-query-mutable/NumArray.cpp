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
        // 再更新数组C，update操作，BIT树往右上走，i递增
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
        // sum操作，BIT树往左上走，i递减
        while (i > 0) {
            ret += c[i];
            i -= lowbit(i);
        }
        return ret;
    }
private:
    vector<int> a, c;
};

/**
    线段树解，超时。。。
*/

class NumArray {
public:
    NumArray(vector<int> nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    int sumRange(int i, int j) {
        if(!root || i > root->end || j < root->start) return 0;
        return sumRange(root, i, j);
    }

private:
    class Node {
    public:
        int start, end, sum;
        Node * left, * right;
        Node(int start, int end, int sum = 0, Node* left = NULL, Node* right = NULL)
        :start(start), end(end), sum(sum), left(left), right(right) {}
    };
    Node* root;

    Node* build(vector<int> nums, int start, int end) {
        if (start > end) return NULL;
        Node* ret = new Node(start, end);
        if (start == end) {
            ret->sum = nums[start];
        }
        else {
            int mid = start + (end - start) / 2;
            ret->left = build(nums, start, mid);
            ret->right = build(nums, mid + 1, end);
            ret->sum = ret->left->sum + ret->right->sum;
        }
        return ret;
    }

    void update(Node* root, int i, int val) {
        if (root->start == root->end) {
            root->sum = val;
        }
        else {
            int mid = root->start + (root->end - root->start) / 2;
            if (i <= mid) update(root->left, i, val);
            else update(root->right, i, val);

            root->sum = root->left->sum + root->right->sum;
        }
    }

    int sumRange(Node* root, int i, int j) {
        if(i <= root->start && j >= root->end) return root->sum;

        if (root->start == i && root->end == j) {
            return root->sum;
        }
        else {
            int mid = root->start + (root->end - root->start) / 2;

            if (i > mid) return sumRange(root->right, i, j);
            else if (j <= mid) return sumRange(root->left, i, j);
            else return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
        }
    }
};
