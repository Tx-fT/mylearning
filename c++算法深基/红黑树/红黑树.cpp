/**
 * 红黑树 (Red-Black Tree) 教学模板
 * ====================================
 *
 * 【红黑树的5条性质】
 * 1. 每个节点要么是红色，要么是黑色
 * 2. 根节点永远是黑色
 * 3. 每个 NIL 叶子节点是黑色（这里用哨兵节点 nil 代替）
 * 4. 红色节点的两个子节点必须是黑色（不存在连续红色） 
 * 5. 从任意节点到其所有后代 NIL 的路径上，黑色节点数量相同（黑高相等）

 * 颜色是一种"记账"手段：黑色负责保证高度不会太高（每路径一样多），红色允许插空子但不连红。两色配合，用 O(1) 次旋转就维持住近似平衡。

 uncle为红色节点代表等待黑未满状态，所以不旋以平衡(相持)
      为黑色代表满状态，旋以平衡

 * 【红黑树的核心思想】
 * 红黑树是一种"近似平衡"的二叉搜索树。
 * 它不像 AVL 树那样严格要求高度差 ≤1，而是通过颜色约束来保证：
 *   最长路径 ≤ 2 × 最短路径
 * 这意味着查找/插入/删除都是 O(log n)。
 *
 * 【与 AVL 树的对比】
 *   AVL 树：严格平衡，查找更快，但插入删除旋转次数多
 *   红黑树：近似平衡，插入删除旋转次数少，综合性能更优
 *   → C++ STL 的 map/set 底层就是红黑树（实际中多用红黑树）
 */

#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V = K>
class RBTree {
   private:
    // 颜色枚举
    enum Color { RED, BLACK };

    // 红黑树节点
    struct Node {
        K key;
        V val;
        Color color;
        Node *left, *right, *parent;

        Node(K k, V v, Color c = RED)
            : key(k), val(v), color(c), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root;  // 根节点
    Node *nil;   // 哨兵 NIL 节点（黑色），所有空指针指向它

    // ==================== 内部工具函数 ====================
    //建
    Node* createNode(K key, V val, Color color = RED) {
        Node *node = new Node(key, val, color);
        node->left = node->right = node->parent = nil;
        return node;
    }

    //删
    void freeTree(Node *node) {
        if (node == nil) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

    // 返回以 node 为根的子树中的最小节点
    Node* minimum(Node *node) const {
        while (node->left != nil)
            node = node->left;
        return node;
    }

    // 返回以 node 为根的子树中的最大节点
    Node* maximum(Node *node) const {
        while (node->right != nil)
            node = node->right;
        return node;
    }

    // ==================== 旋转操作 ====================
    /**
     * 左旋 (Left Rotation)
     * ====================
     * 对节点 x 进行左旋，意味着让 x 的右孩子 y "上升"成为 x 的父节点，
     * 而 x 变成 y 的左孩子。
     *
     * 旋转前:              旋转后:
     *     x                   y
     *    / \                 / \
     *   α   y       →       x   γ
     *      / \             / \
     *     β   γ           α   β
     *
     * 步骤:
     * 1. y = x->right（记住 x 的右孩子）
     * 2. x->right = y->left（把 y 的左子树 β 过继给 x 当右子树）
     * 3. 如果 β ≠ nil，β->parent = x
     * 4. y->parent = x->parent（y 接管 x 的父亲关系）
     * 5. 根据 x 是左/右/根，把 y 挂到对应的位置
     * 6. y->left = x, x->parent = y（x 成为 y 的左孩子）
     *
     * 【为什么叫"左旋"？因为 x 被"拉"到了左边/下方】
     */
    void leftRotate(Node *x) {
        Node *y = x->right;          // 步骤1: y 是 x 的右孩子
        x->right = y->left;          // 步骤2: β 过继给 x

        if (y->left != nil)          // 步骤3: β 认新爹
            y->left->parent = x;

        y->parent = x->parent;       // 步骤4: y 接管 x 的父子关系

        if (x->parent == nil)        // 步骤5: 如果 x 原来是根
            root = y;
        else if (x == x->parent->left)  // x 是左孩子
            x->parent->left = y;
        else                            // x 是右孩子
            x->parent->right = y;

        y->left = x;                 // 步骤6: x 成为 y 的左孩子
        x->parent = y;
    }

    /**
     * 右旋 (Right Rotation)
     * ====================
     * 对节点 y 进行右旋，是左旋的镜像操作。
     *
     * 旋转前:              旋转后:
     *       y                 x
     *      / \               / \
     *     x   γ     →       α   y
     *    / \                   / \
     *   α   β                 β   γ
     *
     * 【理解技巧】左旋：逆时针"拉下"左边节点
     *           右旋：顺时针"拉下"右边节点
     *           旋转不破坏 BST 性质（中序遍历不变）
     */
    void rightRotate(Node *y) {
        Node *x = y->left;           // 记住 y 的左孩子
        y->left = x->right;          // β 过继给 y

        if (x->right != nil)
            x->right->parent = y;

        x->parent = y->parent;       // x 接管 y 的父子关系

        if (y->parent == nil)        // y 原来是根
            root = x;
        else if (y == y->parent->right)  // y 是右孩子
            y->parent->right = x;
        else                              // y 是左孩子
            y->parent->left = x;

        x->right = y;                // y 成为 x 的右孩子
        y->parent = x;
    }

    // ==================== 插入修复 ====================
    /**
     * 插入修复 (Insert Fixup)
     * ========================
     * 新插入的节点永远是红色的（这样不破坏性质5的黑高）。
     * 但如果父节点也是红色，就违反了性质4（不能连续两个红）。
     *
     * 修复的核心：把"违规的红色"向上推，直到根，或者可以安全吸收。
     *
     * 三种情况（z 是当前节点，z.p 是红色为前提）：
     *
     * 【情况1】叔叔 y 是红色
     *     把父亲和叔叔都变黑，祖父变红，问题上移到祖父。
     *     （相当于把祖父的黑色"分给"两个儿子）
     *
     * 【情况2】叔叔 y 是黑色，且 z 是右孩子
     *     对父亲左旋，把 z 变成左孩子，转化为情况3。
     *
     * 【情况3】叔叔 y 是黑色，且 z 是左孩子
     *     父亲变黑，祖父变红，对祖父右旋。
     *     （父亲"接管"祖父的位置，颜色互换保证黑高不变）
     */
    void insertFixup(Node *z) {
        // 只有父节点是红色时才需要修复（违反了性质4）
        while (z->parent->color == RED) {
            // 父节点是祖父的左孩子（对称的两种情况）
            if (z->parent == z->parent->parent->left) {
                Node *y = z->parent->parent->right;  // 叔叔节点

                if (y->color == RED) {
                    // 【情况1】叔叔是红色
                    // 操作：父黑、叔黑、祖父红，z 跳到祖父继续
                    // 为什么？把祖父的黑色分给两个儿子，祖父变红相当于把"红色危机"上移
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        // 【情况2】叔叔黑 + z 是右孩子
                        // 左旋把 z 转到外侧，变成情况3
                        z = z->parent;
                        leftRotate(z);
                    }
                    // 【情况3】叔叔黑 + z 是左孩子
                    // 父变黑、祖父变红、右旋祖父，彻底解决！
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                // 父节点是祖父的右孩子（与上面完全对称）
                Node *y = z->parent->parent->left;  // 叔叔节点

                if (y->color == RED) {
                    // 情况1: 叔叔红
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        // 情况2: 叔叔黑 + z 是内侧孙子，先右旋转外侧
                        z = z->parent;
                        rightRotate(z);
                    }
                    // 情况3: 叔叔黑 + z 是外侧孙子
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;  // 根永远是黑色（性质2）
    }

    // ==================== 删除修复 ====================
    /**
     * 用节点 v 替换节点 u 在树中的位置（移植子树）
     * u 的父节点现在指向 v
     */
    void transplant(Node *u, Node *v) {
        if (u->parent == nil)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    /**
     * 删除修复 (Delete Fixup)
     * ========================
     * 前提：节点 x 是"双重黑色"（代替了被删除的黑色节点）
     * 需要把多余的黑色"推"到可以安全吸收的位置。
     *
     * 四种情况（x 是左孩子时，对称情况类推）：
     *
     * 【情况1】兄弟 w 是红色
     *     兄弟变黑，父变红，对父左旋，更新兄弟。
     *     转化为情况2/3/4。
     *
     * 【情况2】兄弟 w 黑色，w 的两个孩子都是黑色
     *     兄弟变红，x 上移到父节点。
     *     （把多余黑色和兄弟的黑色合并上移到父亲）
     *
     * 【情况3】兄弟 w 黑色，w 左孩子红、右孩子黑
     *     w 的左孩子变黑，w 变红，对 w 右旋，更新兄弟。
     *     转化为情况4。
     *
     * 【情况4】兄弟 w 黑色，w 右孩子是红色
     *     w 的颜色 = 父的颜色，父变黑，w 右孩子变黑，对父左旋。
     *     多余黑色被吸收，终止！
     */
    void deleteFixup(Node *x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Node *w = x->parent->right;  // 兄弟节点

                if (w->color == RED) {
                    // 【情况1】兄弟红色 → 兄弟变黑，父变红，左旋父，兄弟更新
                    w->color = BLACK;
                    x->parent->color = RED;
                    leftRotate(x->parent);
                    w = x->parent->right;
                }

                if (w->left->color == BLACK && w->right->color == BLACK) {
                    // 【情况2】兄弟黑 + 两个侄子都黑
                    w->color = RED;
                    x = x->parent;  // 双重黑色上移到父亲
                } else {
                    if (w->right->color == BLACK) {
                        // 【情况3】兄弟黑 + 左侄子红 + 右侄子黑
                        w->left->color = BLACK;
                        w->color = RED;
                        rightRotate(w);
                        w = x->parent->right;  // 兄弟更新
                    }
                    // 【情况4】兄弟黑 + 右侄子红（至少）
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(x->parent);
                    x = root;  // 多余黑色被吸收，退出循环
                }
            } else {
                // x 是右孩子（与上面完全对称）
                Node *w = x->parent->left;

                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rightRotate(x->parent);
                    w = x->parent->left;
                }

                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    // ==================== 遍历 & 验证 ====================

    // 中序遍历（验证 BST 性质）
    void inorder(Node *node, vector<pair<K, V>> &res) const {
        if (node == nil) return;
        inorder(node->left, res);
        res.push_back({node->key, node->val});
        inorder(node->right, res);
    }

    vector<pair<K, V>> inorder() const {
        vector<pair<K, V>> res;
        inorder(root, res);
        return res;
    }

    // 前序遍历（查看树结构）
    void preorder(Node *node, int depth, vector<string> &lines) const {
        if (node == nil) return;
        string line(depth * 2, ' ');
        ostringstream oss;
        oss << node->key;
        line += oss.str();
        line += (node->color == RED ? "(R)" : "(B)");
        lines.push_back(line);
        preorder(node->left, depth + 1, lines);
        preorder(node->right, depth + 1, lines);
    }

    // 验证性质4：没有连续红色
    bool checkNoConsecutiveRed(Node *node) const {
        if (node == nil) return true;
        if (node->color == RED) {
            if (node->left->color == RED || node->right->color == RED)
                return false;  // 红节点的孩子必须是黑色
        }
        return checkNoConsecutiveRed(node->left) &&
               checkNoConsecutiveRed(node->right);
    }

    // 验证性质5：所有路径的黑高相同
    // 返回值：黑高；-1 表示不平衡
    int checkBlackHeight(Node *node) const {
        if (node == nil) return 1;  // nil 算一个黑色

        int leftBH = checkBlackHeight(node->left);
        int rightBH = checkBlackHeight(node->right);

        if (leftBH == -1 || rightBH == -1 || leftBH != rightBH)
            return -1;  // 不平衡

        return leftBH + (node->color == BLACK ? 1 : 0);
    }

   public:
    // ==================== 构造/析构 ====================

    RBTree() {
        nil = new Node(K{}, V{}, BLACK);  // 哨兵节点
        nil->left = nil->right = nil->parent = nil;
        root = nil;
    }

    ~RBTree() {
        freeTree(root);
        delete nil;
    }

    // 禁止拷贝（简化实现）
    RBTree(const RBTree&) = delete;
    RBTree& operator=(const RBTree&) = delete;

    // ==================== 查找操作（公开） ====================

    Node* find(K key) const {
        Node *x = root;
        while (x != nil) {
            if (key < x->key)
                x = x->left;
            else if (key > x->key)
                x = x->right;
            else
                return x;  // 找到了
        }
        return nullptr;  // 没找到（注意区分 nil 和 nullptr）
    }

    bool count(K key) const { return find(key) != nullptr; }

    V get(K key, V defaultVal = V{}) const {
        Node *node = find(key);
        return node ? node->val : defaultVal;
    }

    // ==================== 插入操作（公开） ====================

    /**
     * 插入新节点
     * ============
     * 1. 像普通 BST 一样找到插入位置
     * 2. 新节点染红色，挂到树上
     * 3. 调用 insertFixup 修复红黑性质
     */
    void insert(K key, V val) {
        Node *z = createNode(key, val, RED);  // 新节点默认红色
        Node *y = nil;      // y 记录 z 的父节点
        Node *x = root;     // x 用于遍历找位置

        // 1. 标准 BST 插入：找到应该插入的位置
        while (x != nil) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else if (z->key > x->key)
                x = x->right;
            else {
                // key 已存在，更新 value 并返回
                x->val = val;
                delete z;
                return;
            }
        }

        // 2. 挂载节点
        z->parent = y;
        if (y == nil)
            root = z;           // 树为空，z 成为根
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;

        // 3. 修复红黑树性质
        insertFixup(z);
    }

    // 便捷接口：只传 key（当 set 用）
    void insert(K key) {
        insert(key, key);
    }

    // operator[] 方便使用（类似 map）
    V& operator[](K key) {
        Node *node = find(key);
        if (node) return node->val;
        insert(key, V{});  // 不存在则插入默认值
        return find(key)->val;
    }

    // ==================== 删除操作（公开） ====================

    /**
     * 删除节点
     * ========
     * BST 删除 + 颜色修复：
     * 1. 如果被删节点有两个孩子，用后继节点替换（复制 key/val）
     * 2. 实际被移除的节点是 z 或其后继（最多一个孩子）
     * 3. 如果移走的是黑色节点，调用 deleteFixup
     */
    bool erase(K key) {
        Node *z = find(key);
        if (!z) return false;  // 键不存在

        Node *y = z;          // y 是实际要从树中移除的节点
        Node *x;               // x 是填补 y 位置的节点
        Color yOriginalColor = y->color;

        if (z->left == nil) {
            // 情况A: 左子树为空，右孩子（或 nil）替换
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == nil) {
            // 情况B: 右子树为空，左孩子替换
            x = z->left;
            transplant(z, z->left);
        } else {
            // 情况C: 有两个孩子，找后继 y
            y = minimum(z->right);  // 后继：右子树的最小节点
            yOriginalColor = y->color;
            x = y->right;           // y 最多只有一个右孩子

            if (y->parent == z) {
                // 后继就是 z 的直接右孩子
                x->parent = y;
            } else {
                // 后继在更深处，先把 y 从原位置移除
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            // y 替换 z 的位置
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;  // y 继承 z 的颜色
        }

        delete z;  // 释放内存

        // 如果移走的是黑色节点，需要修复
        // 为什么？移走黑色节点会破坏性质5（某路径黑高少1）
        if (yOriginalColor == BLACK)
            deleteFixup(x);

        return true;
    }

    // ==================== 工具查询（公开） ====================

    int size() const {
        vector<pair<K, V>> res = inorder();
        return res.size();
    }

    bool empty() const { return root == nil; }

    V minKey() const {
        Node *node = minimum(root);
        return node != nil ? node->key : V{};
    }

    V maxKey() const {
        Node *node = maximum(root);
        return node != nil ? node->key : V{};
    }

    // ==================== 验证 & 打印（公开） ====================

    bool isValidRBTree() const {
        if (root == nil) return true;
        if (root->color == RED) return false;            // 性质2: 根必须是黑
        if (!checkNoConsecutiveRed(root)) return false;   // 性质4
        return checkBlackHeight(root) != -1;              // 性质5
    }

    void printInorder() const {
        auto items = inorder();
        cout << "[";
        for (int i = 0; i < (int)items.size(); i++) {
            if (i > 0) cout << ", ";
            cout << items[i].first << ":" << items[i].second;
        }
        cout << "]\n";
    }

    void printTree() const {
        cout << "=== 红黑树结构 (前序, R=红 B=黑) ===\n";
        vector<string> lines;
        preorder(root, 0, lines);
        for (auto &s : lines) cout << s << '\n';
        cout << "合法: " << (isValidRBTree() ? "✅" : "❌") << '\n';
    }
};

// ==================== 测试用例 ====================

void testBasic() {
    cout << "========== 基本插入 & 查找测试 ==========\n";
    RBTree<int, string> tree;

    tree.insert(10, "ten");
    tree.insert(5, "five");
    tree.insert(15, "fifteen");
    tree.insert(3, "three");
    tree.insert(7, "seven");
    tree.insert(12, "twelve");
    tree.insert(18, "eighteen");

    cout << "中序遍历: ";
    tree.printInorder();

    cout << "查找 7: " << tree.get(7, "N/A") << '\n';
    cout << "查找 99: " << tree.get(99, "N/A") << '\n';
    cout << "包含 12: " << (tree.count(12) ? "是" : "否") << '\n';
    cout << "包含 0: " << (tree.count(0) ? "是" : "否") << '\n';
}

void testRedBlackProperties() {
    cout << "\n========== 红黑性质验证测试 ==========\n";
    RBTree<int, int> tree;

    // 插入 1~20，验证每次插入后红黑性质保持
    for (int i = 1; i <= 20; i++) {
        tree.insert(i, i * 100);
        if (!tree.isValidRBTree()) {
            cout << "❌ 插入 " << i << " 后红黑性质被破坏!\n";
            return;
        }
    }
    cout << "✅ 插入 1~20 后红黑树性质全部保持\n";
    cout << "黑高检查通过\n";

    tree.printTree();
}

void testDelete() {
    cout << "\n========== 删除测试 ==========\n";
    RBTree<int, int> tree;

    // 构建一棵树
    vector<int> keys = {7, 3, 18, 10, 22, 8, 11, 26};
    for (int k : keys) tree.insert(k, k);

    cout << "原始树: ";
    tree.printInorder();
    cout << "初始合法: " << (tree.isValidRBTree() ? "✅" : "❌") << '\n';

    // 逐个删除并验证
    vector<int> toDelete = {10, 18, 3, 7};
    for (int k : toDelete) {
        cout << "删除 " << k << "... ";
        tree.erase(k);
        cout << (tree.isValidRBTree() ? "✅" : "❌") << " | ";
        tree.printInorder();
    }

    // 删除不存在的键
    cout << "删除不存在的键 999: " << (tree.erase(999) ? "成功" : "失败(不存在)") << '\n';
}

void testStress() {
    cout << "\n========== 压力测试 ==========\n";
    RBTree<int, int> tree;

    const int N = 1000;
    // 随机插入
    vector<int> nums(N);
    iota(nums.begin(), nums.end(), 1);
    shuffle(nums.begin(), nums.end(), mt19937(random_device()()));

    for (int x : nums) tree.insert(x, x);
    cout << "插入 " << N << " 个节点后合法: " << (tree.isValidRBTree() ? "✅" : "❌") << '\n';

    // 随机删除一半
    shuffle(nums.begin(), nums.end(), mt19937(random_device()()));
    for (int i = 0; i < N / 2; i++) {
        tree.erase(nums[i]);
        if (i % 200 == 199 && !tree.isValidRBTree()) {
            cout << "❌ 删除第 " << i + 1 << " 个节点时性质被破坏\n";
            return;
        }
    }
    cout << "随机删除 " << N / 2 << " 个节点后合法: " << (tree.isValidRBTree() ? "✅" : "❌") << '\n';
    cout << "剩余节点数: " << tree.size() << '\n';
}

void testMapUsage() {
    cout << "\n========== 类似 map 的用法 ==========\n";
    RBTree<string, int> freq;

    freq["apple"] = 5;
    freq["banana"] = 3;
    freq["cherry"] = 8;

    cout << "apple: " << freq["apple"] << '\n';
    cout << "banana: " << freq.get("banana") << '\n';
    cout << "grape (默认): " << freq.get("grape", -1) << '\n';
    freq.printInorder();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    testBasic();
    testRedBlackProperties();
    testDelete();
    testStress();
    testMapUsage();

    cout << "\n🎉 所有测试完成!\n";
    return 0;
}
