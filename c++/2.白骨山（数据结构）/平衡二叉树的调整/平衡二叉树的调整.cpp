#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// 定义AVL树节点结构
typedef struct AVLNode {
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

// 获取节点高度
int getHeight(AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// 获取平衡因子
int getBalanceFactor(AVLNode *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// 更新节点高度
void updateHeight(AVLNode *node) {
    if (node == NULL)
        return;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 创建新节点
AVLNode* createNode(int data) {
    AVLNode *newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1. LL旋转（右旋）
AVLNode* rightRotate(AVLNode *y) {
    printf("执行LL旋转（右旋）: 节点 %d\n", y->data);
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    
    // 执行旋转
    x->right = y;
    y->left = T2;
    
    // 更新高度
    updateHeight(y);
    updateHeight(x);
    
    return x; // 返回新的根节点
}

// 2. RR旋转（左旋）
AVLNode* leftRotate(AVLNode *x) {
    printf("执行RR旋转（左旋）: 节点 %d\n", x->data);
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    
    // 执行旋转
    y->left = x;
    x->right = T2;
    
    // 更新高度
    updateHeight(x);
    updateHeight(y);
    
    return y; // 返回新的根节点
}

// 3. LR旋转（先左旋再右旋）
AVLNode* leftRightRotate(AVLNode *z) {
    printf("执行LR旋转: 节点 %d\n", z->data);
    // 先对左子树进行左旋
    printf("  先对左子树 %d 进行左旋\n", z->left->data);
    z->left = leftRotate(z->left);
    // 再对根节点进行右旋
    printf("  再对根节点 %d 进行右旋\n", z->data);
    return rightRotate(z);
}

// 4. RL旋转（先右旋再左旋）
AVLNode* rightLeftRotate(AVLNode *z) {
    printf("执行RL旋转: 节点 %d\n", z->data);
    // 先对右子树进行右旋
    printf("  先对右子树 %d 进行右旋\n", z->right->data);
    z->right = rightRotate(z->right);
    // 再对根节点进行左旋
    printf("  再对根节点 %d 进行左旋\n", z->data);
    return leftRotate(z);
}

// 平衡节点
AVLNode* balanceNode(AVLNode *node) {
    if (node == NULL)
        return node;
    
    updateHeight(node);
    int balance = getBalanceFactor(node);
    
    // 显示平衡因子
    printf("节点 %d: 高度=%d, 平衡因子=%d\n", node->data, node->height, balance);
    
    // LL情况
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        printf("检测到LL失衡情况\n");
        return rightRotate(node);
    }
    
    // RR情况
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        printf("检测到RR失衡情况\n");
        return leftRotate(node);
    }
    
    // LR情况
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        printf("检测到LR失衡情况\n");
        return leftRightRotate(node);
    }
    
    // RL情况
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        printf("检测到RL失衡情况\n");
        return rightLeftRotate(node);
    }
    
    return node;
}

// 插入节点
AVLNode* insert(AVLNode *node, int data) {
    printf("\n插入节点 %d:\n", data);
    
    // 1. 标准的BST插入
    if (node == NULL) {
        printf("  创建新节点\n");
        return createNode(data);
    }
    
    if (data < node->data) {
        printf("  向左子树插入\n");
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        printf("  向右子树插入\n");
        node->right = insert(node->right, data);
    }
    else {
        printf("  节点已存在，不重复插入\n");
        return node; // 不允许重复值
    }
    
    // 2. 更新高度并平衡
    printf("  平衡节点 %d\n", node->data);
    return balanceNode(node);//也在递归之内
}

// 打印树形结构
void printTree(AVLNode *root, int space) {
    if (root == NULL)
        return;
    
    // 增加缩进
    space += 5;
    
    // 先打印右子树
    printTree(root->right, space);
    
    // 打印当前节点
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d(%d)\n", root->data, root->height);
    
    // 打印左子树
    printTree(root->left, space);
}

// 中序遍历
void inOrderTraversal(AVLNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// 前序遍历
void preOrderTraversal(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 释放树的内存
void freeTree(AVLNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// 显示树的信息
void displayTreeInfo(AVLNode *root, const char *testName) {
    printf("\n========== %s ==========\n", testName);
    printf("树形结构:\n");
    printTree(root, 0);
    
    printf("\n中序遍历: ");
    inOrderTraversal(root);
    
    printf("\n前序遍历: ");
    preOrderTraversal(root);
    
    printf("\n根节点: %d (高度: %d)\n", root->data, root->height);
    printf("============================\n\n");
}

// 实验案例1: LL旋转测试
void testLLRotation() {
    printf("\n****************************************************************\n");
    printf("实验案例1: LL旋转测试\n");
    printf("插入序列: 30 -> 20 -> 10\n");
    printf("插入10后，节点30失衡（左子树高度-右子树高度=2），触发LL旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    printf("\n1. 插入30:");
    root = insert(root, 30);
    displayTreeInfo(root, "插入30后");
    
    printf("\n2. 插入20:");
    root = insert(root, 20);
    displayTreeInfo(root, "插入20后");
    
    printf("\n3. 插入10:");
    root = insert(root, 10);
    displayTreeInfo(root, "插入10后（触发LL旋转）");
    
    freeTree(root);
}

// 实验案例2: RR旋转测试
void testRRRotation() {
    printf("\n****************************************************************\n");
    printf("实验案例2: RR旋转测试\n");
    printf("插入序列: 10 -> 20 -> 30\n");
    printf("插入30后，节点10失衡（右子树高度-左子树高度=-2），触发RR旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    printf("\n1. 插入10:");
    root = insert(root, 10);
    displayTreeInfo(root, "插入10后");
    
    printf("\n2. 插入20:");
    root = insert(root, 20);
    displayTreeInfo(root, "插入20后");
    
    printf("\n3. 插入30:");
    root = insert(root, 30);
    displayTreeInfo(root, "插入30后（触发RR旋转）");
    
    freeTree(root);
}

// 实验案例3: LR旋转测试
void testLRRotation() {
    printf("\n****************************************************************\n");
    printf("实验案例3: LR旋转测试\n");
    printf("插入序列: 30 -> 10 -> 20\n");
    printf("插入20后，节点30失衡（左子树的右子树高度大），触发LR旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    printf("\n1. 插入30:");
    root = insert(root, 30);
    displayTreeInfo(root, "插入30后");
    
    printf("\n2. 插入10:");
    root = insert(root, 10);
    displayTreeInfo(root, "插入10后");
    
    printf("\n3. 插入20:");
    root = insert(root, 20);
    displayTreeInfo(root, "插入20后（触发LR旋转）");
    
    freeTree(root);
}

// 实验案例4: RL旋转测试
void testRLRotation() {
    printf("\n****************************************************************\n");
    printf("实验案例4: RL旋转测试\n");
    printf("插入序列: 10 -> 30 -> 20\n");
    printf("插入20后，节点10失衡（右子树的左子树高度大），触发RL旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    printf("\n1. 插入10:");
    root = insert(root, 10);
    displayTreeInfo(root, "插入10后");
    
    printf("\n2. 插入30:");
    root = insert(root, 30);
    displayTreeInfo(root, "插入30后");
    
    printf("\n3. 插入20:");
    root = insert(root, 20);
    displayTreeInfo(root, "插入20后（触发RL旋转）");
    
    freeTree(root);
}

// 实验案例5: 综合测试
void testComprehensive() {
    printf("\n****************************************************************\n");
    printf("实验案例5: 综合测试\n");
    printf("插入序列: 40 -> 20 -> 60 -> 10 -> 30 -> 50 -> 70 -> 5 -> 15\n");
    printf("测试多种旋转的组合情况\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    int values[] = {40, 20, 60, 10, 30, 50, 70, 5, 15};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        printf("\n步骤%d: 插入%d", i + 1, values[i]);
        root = insert(root, values[i]);
        
        char title[50];
        sprintf(title, "插入%d后", values[i]);
        displayTreeInfo(root, title);
    }
    
    freeTree(root);
}

// 实验案例6: 复杂LR旋转测试
void testComplexLR() {
    printf("\n****************************************************************\n");
    printf("实验案例6: 复杂LR旋转测试\n");
    printf("插入序列: 40 -> 20 -> 50 -> 10 -> 30 -> 25\n");
    printf("插入25后触发复杂的LR旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    int values[] = {40, 20, 50, 10, 30, 25};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        printf("\n步骤%d: 插入%d", i + 1, values[i]);
        root = insert(root, values[i]);
        
        char title[50];
        sprintf(title, "插入%d后", values[i]);
        if (i == n - 1) strcat(title, "（触发LR旋转）");
        displayTreeInfo(root, title);
    }
    
    freeTree(root);
}

// 实验案例7: 复杂RL旋转测试
void testComplexRL() {
    printf("\n****************************************************************\n");
    printf("实验案例7: 复杂RL旋转测试\n");
    printf("插入序列: 40 -> 20 -> 50 -> 60 -> 45 -> 55\n");
    printf("插入55后触发复杂的RL旋转\n");
    printf("****************************************************************\n");
    
    AVLNode *root = NULL;
    
    int values[] = {40, 20, 50, 60, 45, 55};
    int n = sizeof(values) / sizeof(values[0]);
    
    for (int i = 0; i < n; i++) {
        printf("\n步骤%d: 插入%d", i + 1, values[i]);
        root = insert(root, values[i]);
        
        char title[50];
        sprintf(title, "插入%d后", values[i]);
        if (i == n - 1) strcat(title, "（触发RL旋转）");
        displayTreeInfo(root, title);
    }
    
    freeTree(root);
}

int main() {
    printf("================ AVL树旋转操作实验案例 ================\n");
    
    // 运行所有实验案例
    testLLRotation();
    testRRRotation();
    testLRRotation();
    testRLRotation();
    testComplexLR();
    testComplexRL();
    testComprehensive();
    
    printf("\n实验案例执行完毕！\n");
    printf("通过以上实验可以看到AVL树如何通过四种旋转保持平衡。\n");
    
    return 0;
}
