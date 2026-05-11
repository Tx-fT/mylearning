//数据结构
//概念（思路打开）
//数据对象在计算机中的组织方法
//1.逻辑结构（线性结构1对1）（树形结构1对多）（图的结构多对多）
//数据对象与加之其上的操作有关
//完成此操作的方法称为算法
//什么是好的算法
//1.空间复杂度S(n)2.时间复杂度T(n)
//平均复杂度，最坏情况复杂度
//复杂度的渐进表示法O上界，Ω下届
//1<logn<n<nlogn<n^2;*法复杂度相乘+法取最大值
//（加法忽略不计时间复杂度，数乘法）
//（递归程序函数未完成会储存）
//最大子列和
//分而治之（二分法）
//#include <stdio.h>
//#include <limits.h>
//
//// 计算跨越中点的最大子列和
//int maxCrossingSum(int arr[], int left, int mid, int right) {
//    // 从中点向左扫描
//    int sum = 0;
//    int left_sum = INT_MIN;
//    for (int i = mid; i >= left; i--) {
//        sum += arr[i];
//        if (sum > left_sum)
//            left_sum = sum;
//    }
//    
//    // 从中点向右扫描
//    sum = 0;
//    int right_sum = INT_MIN;
//    for (int i = mid + 1; i <= right; i++) {
//        sum += arr[i];
//        if (sum > right_sum)
//            right_sum = sum;
//    }
//    
//    return left_sum + right_sum;
//}
//
//// 分治法求解最大子列和
//int maxSubArraySum(int arr[], int left, int right) {
//    // 基本情况：只有一个元素
//    if (left == right)
//        return arr[left];
//    
//    // 找到中点
//    int mid = left + (right - left) / 2;
//    
//    // 递归求解三部分的最大和
//    int left_sum = maxSubArraySum(arr, left, mid);
//    int right_sum = maxSubArraySum(arr, mid + 1, right);
//    int cross_sum = maxCrossingSum(arr, left, mid, right);
//    
//    // 返回三者中的最大值
//    int max = left_sum;
//    if (right_sum > max) max = right_sum;
//    if (cross_sum > max) max = cross_sum;
//    
//    return max;//这个return可以对应max深度-1的表层
//}
//
//// 封装函数，方便调用
//int maxSubArray(int arr[], int n) {
//    if (n <= 0) return 0;
//    return maxSubArraySum(arr, 0, n - 1);
//}
//动态规划
//#include<bits/stdc++.h>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	int arr[200001];
//	int dp[200001];
//	for(int i=1;i<=n;i++){
//		cin>>arr[i];
//	} 
//	int max1;
//    dp[1]=arr[1];
//    max1=dp[1];
//	for(int i=2;i<=n;i++){
//		dp[i]=max(dp[i-1]+arr[i],arr[i]);
//		max1=max(max1,dp[i]);
//	}
//	cout<<max1;
//	return 0;
//}
//线性结构
//线性表 可以用数组实现，也可以用链表实现
//数据不同表述方法数组，链表
//建立一个结构体包含data[n] index,index对应data中的值
//其实跟数组差不多好处是
//其建立：
//#include<iostream>
//using namespace std;
//typedef struct node *List;//可以用list表示struct node*
//
//struct node {
//    int *data;           // 动态分配数组
//    int max_size;        // 数组最大容量
//    int last;            // 最后一个元素的索引（-1表示空表）
//};
//
//// 创建列表
//List createList(int max_size) {
//    List L = (List)malloc(sizeof(struct node));//申请结构模拟数组实现
//    L->data = (int *)malloc(max_size * sizeof(int));
//    L->max_size = max_size;
//    L->last = -1;        // 空表或者用data[]
//    return L;
//}
////对比数组可以精准控制last范围
////为什要使用malloc申请内存因为只有程序运行才会知晓内存例如链表会在头节点联系更多节点
////所以叫做动态的内存可以随时分配，没有动态内存分配，C 语言就无法构建复杂的数据结构和处理真实世界中的不确定数据需求。
//// 销毁列表
//void destroyList(List L) {
//    free(L->data);
//    free(L);
//}
//
//// 使用示例
//int main() {
//    List p = createList(100);  // 创建容量为100的列表
//    
//    // 添加元素
//    if (p->last < p->max_size - 1) {
//        p->last++;
//        p->data[p->last] = 42;
//    }
//    
//    destroyList(p);
//    return 0;
//}
//链表（略）
//注意头节点的next不能变，用temp
//查找能找前一个找前一个，遍历过成黑户
//双向链表
//#include <stdio.h>
//#include <stdlib.h>

// 双向链表节点定义
//typedef struct DNode {
//    int data;               // 数据域
//    struct DNode *prev;     // 前驱指针
//    struct DNode *next;     // 后继指针
//} DNode, *DLinkedList;
//// 创建新节点
//DNode* createNode(int data) {
//    DNode *newNode = (DNode*)malloc(sizeof(DNode));
//    if (newNode == NULL) {
//        printf("内存分配失败！\n");
//        exit(1);
//    }
//    newNode->data = data;
//    newNode->prev = NULL;
//    newNode->next = NULL;
//    return newNode;
//}
// 带头节点的双向链表（更常用）
//typedef struct DNode {
//    int data;
//    struct DNode *prev;
//    struct DNode *next;
//} DNode;
//
//typedef struct {
//    DNode *head;    // 头节点（不存储数据）
//    DNode *tail;    // 尾指针（可选）
//    int size;       // 链表长度
//} DLinkedList;
//
//// 初始化链表
//void initList(DLinkedList *list) {
//    list->head = (DNode*)malloc(sizeof(DNode));
//    if (list->head == NULL) {
//        printf("内存分配失败！\n");
//        exit(1);
//    }
//    list->head->prev = NULL;
//    list->head->next = NULL;
//    list->tail = list->head;  // 初始时头尾相同
//    list->size = 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//// 节点定义
//typedef struct DNode {
//    int data;
//    struct DNode *prev;
//    struct DNode *next;
//} DNode;
//
//// 链表定义
//typedef struct {
//    DNode *head;
//    DNode *tail;
//    int size;
//} DLinkedList;
//
//// 1. 初始化链表
//DLinkedList* createList() {
//    DLinkedList *list = (DLinkedList*)malloc(sizeof(DLinkedList));
//    if (!list) return NULL;
//    
//    // 创建头节点**（哨兵节点）
//    list->head = (DNode*)malloc(sizeof(DNode));
//    if (!list->head) {
//        free(list);
//        return NULL;
//    }
//    
//    list->head->data = 0;      // 头节点数据可存储长度或其他信息
//    list->head->prev = NULL;
//    list->head->next = NULL;
//    list->tail = list->head;   // 初始时尾指针指向头节点
//    list->size = 0;
//    
//    return list;
//}
//
//// 2. 判断链表是否为空
//bool isEmpty(DLinkedList *list) {
//    return list->head->next == NULL;
//}
//
//// 3. 获取链表长度
//int getLength(DLinkedList *list) {
//    return list->size;
//}
//
//// 4. 在头部插入
//void insertAtHead(DLinkedList *list, int data) {
//    DNode *newNode = (DNode*)malloc(sizeof(DNode));
//    if (!newNode) return;
//    
//    newNode->data = data;
//    newNode->prev = list->head;
//    newNode->next = list->head->next;
//    
//    if (list->head->next != NULL) {
//        list->head->next->prev = newNode;
//    } else {
//        // 如果是第一个节点，更新尾指针
//        list->tail = newNode;
//    }
//    
//    list->head->next = newNode;
//    list->size++;
//}
//
//// 5. 在尾部插入
//void insertAtTail(DLinkedList *list, int data) {
//    DNode *newNode = (DNode*)malloc(sizeof(DNode));
//    if (!newNode) return;
//    
//    newNode->data = data;
//    newNode->prev = list->tail;//尾节点的意义可以直接找到最后一个
//    newNode->next = NULL;
//    
//    list->tail->next = newNode;
//    list->tail = newNode;
//    list->size++;
//}
//
//// 6. 在指定位置插入
//bool insertAt(DLinkedList *list, int position, int data) {
//    if (position < 0 || position > list->size) {
//        return false;
//    }
//    
//    if (position == 0) {
//        insertAtHead(list, data);
//        return true;
//    }
//    
//    if (position == list->size) {
//        insertAtTail(list, data);
//        return true;
//    }
//    
//    // 找到插入位置的前一个节点
//    DNode *current = list->head->next;
//    for (int i = 0; i < position - 1; i++) {
//        current = current->next;
//    }
//    
//    DNode *newNode = (DNode*)malloc(sizeof(DNode));
//    if (!newNode) return false;
//    
//    newNode->data = data;
//    newNode->prev = current;
//    newNode->next = current->next;
//    
//    current->next->prev = newNode;
//    current->next = newNode;
//    list->size++;
//    
//    return true;
//}
//
//// 7. 删除头部节点
//bool deleteAtHead(DLinkedList *list) {
//    if (isEmpty(list)) return false;
//    
//    DNode *toDelete = list->head->next;
//    list->head->next = toDelete->next;
//    
//    if (toDelete->next != NULL) {
//        toDelete->next->prev = list->head;
//    } else {
//        // 如果删除的是最后一个节点，更新尾指针
//        list->tail = list->head;
//    }
//    
//    free(toDelete);
//    list->size--;
//    return true;
//}
//
//// 8. 删除尾部节点
//bool deleteAtTail(DLinkedList *list) {
//    if (isEmpty(list)) return false;
//    
//    DNode *toDelete = list->tail;
//    list->tail = toDelete->prev;
//    list->tail->next = NULL;
//    
//    free(toDelete);
//    list->size--;
//    return true;
//}
//
//// 9. 删除指定位置节点
//bool deleteAt(DLinkedList *list, int position) {
//    if (position < 0 || position >= list->size) {
//        return false;
//    }
//    
//    if (position == 0) {
//        return deleteAtHead(list);
//    }
//    
//    if (position == list->size - 1) {
//        return deleteAtTail(list);
//    }
//    
//    // 找到要删除的节点
//    DNode *current = list->head->next;
//    for (int i = 0; i < position; i++) {
//        current = current->next;
//    }
//    
//    current->prev->next = current->next;
//    current->next->prev = current->prev;
//    
//    free(current);
//    list->size--;
//    return true;
//}
//
//// 10. 按值删除
//bool deleteByValue(DLinkedList *list, int value) {
//    DNode *current = list->head->next;
//    bool found = false;
//    
//    while (current != NULL) {
//        if (current->data == value) {
//            DNode *toDelete = current;
//            current = current->next;
//            
//            toDelete->prev->next = toDelete->next;
//            if (toDelete->next != NULL) {
//                toDelete->next->prev = toDelete->prev;
//            } else {
//                list->tail = toDelete->prev;
//            }
//            
//            free(toDelete);
//            list->size--;
//            found = true;
//        } else {
//            current = current->next;
//        }
//    }
//    
//    return found;
//}
//
//// 11. 查找节点
//DNode* findNode(DLinkedList *list, int value) {
//    DNode *current = list->head->next;
//    while (current != NULL) {
//        if (current->data == value) {
//            return current;
//        }
//        current = current->next;
//    }
//    return NULL;
//}
//
//// 12. 获取指定位置的节点
//int getAt(DLinkedList *list, int position) {
//    if (position < 0 || position >= list->size) {
//        printf("位置无效！\n");
//        return -1; // 或者使用错误码
//    }
//    
//    DNode *current = list->head->next;
//    for (int i = 0; i < position; i++) {
//        current = current->next;
//    }
//    return current->data;
//}
//
//// 13. 修改指定位置的值
//bool updateAt(DLinkedList *list, int position, int newValue) {
//    if (position < 0 || position >= list->size) {
//        return false;
//    }
//    
//    DNode *current = list->head->next;
//    for (int i = 0; i < position; i++) {
//        current = current->next;
//    }
//    current->data = newValue;
//    return true;
//}
//
//// 14. 清空链表（保留头节点）
//void clearList(DLinkedList *list) {
//    while (!isEmpty(list)) {
//        deleteAtHead(list);
//    }
//    list->tail = list->head;
//}
//
//// 15. 销毁链表（释放所有内存）
//void destroyList(DLinkedList *list) {
//    clearList(list);
//    free(list->head);
//    free(list);
//}
//
//// 16. 打印链表（从头到尾）
//void printListForward(DLinkedList *list) {
//    if (isEmpty(list)) {
//        printf("链表为空\n");
//        return;
//    }
//    
//    DNode *current = list->head->next;
//    printf("正向：NULL <- ");
//    while (current != NULL) {
//        printf("%d", current->data);
//        if (current->next != NULL) {
//            printf(" <-> ");
//        } else {
//            printf(" -> NULL");
//        }
//        current = current->next;
//    }
//    printf("\n");
//}
//
//// 17. 打印链表（从尾到头）
//void printListBackward(DLinkedList *list) {
//    if (isEmpty(list)) {
//        printf("链表为空\n");
//        return;
//    }
//    
//    DNode *current = list->tail;
//    printf("反向：NULL <- ");
//    while (current != list->head) {
//        printf("%d", current->data);
//        if (current->prev != list->head) {
//            printf(" <-> ");
//        } else {
//            printf(" -> NULL");
//        }
//        current = current->prev;
//    }
//    printf("\n");
//}
//
//// 18. 反转链表
//void reverseList(DLinkedList *list) {
//    if (isEmpty(list) || list->size == 1) {
//        return;
//    }
//    
//    DNode *current = list->head->next;
//    DNode *temp = NULL;
//    
//    // 交换每个节点的prev和next指针
//    while (current != NULL) {
//        temp = current->prev;
//        current->prev = current->next;
//        current->next = temp;
//        current = current->prev; // 移动到原下一个节点
//    }
//    
//    // 更新头尾指针
//    if (temp != NULL) {
//        temp = list->head->next;
//        list->head->next = list->tail;
//        list->tail = temp;
//    }
//}


//广义表  多重链表
//线性表的推广
//对于线性表而言，n个元素都是基本单元素
//广义表中，这些元素不仅可以是单元素也可以是另一个广义表
//typedef struct GNode* GList;
//struct GNode{
//	int Tag;//标志域：0表示节点是单元素，1表示节点为广义表
//	union{//（要么tag1 要么tag0）子表指针域与单元素数据data复用，即共用存储空间（非此即彼，只能活一个）
//		int data;
//		GList Sublist;
//	}URegion;
//	GList next;//指向后继节点
//};
//堆栈
//扫描
//62/3-42*+
//6/2-3+4*8；线性表示慢慢部分算当场消化，后入先出叠碗
//栈的顺序储存
//数组实现
//#include<iostream>
//using namespace std;
//#define maxsize 10
//typedef struct snode *stack;
//struct snode{
//	int data[maxsize];
//	int top=-1;
//};
////1.入栈
//void push(stack p,int item){
//	if(p->top==maxsize-1){//maxsize上限管top但top从0开始；
//		printf("满");
//		return;
//	}
//	else{
//		p->data[++(p->top)]=item;
//		return;
//	}
//} 
//int pop(stack p){
//	if(p->top==-1){
//		printf("空");
//		return -1;
//	}
//	else{
//		return p->data[(p->top)--];
//	}
//}
//一个数组实现两个堆栈，要求最大的利用空间。
//只是多加了top2空栈为maxsize；
//且表示满栈是top1和top2地址相同，只要带入加&即可
//1.入栈
//typedef struct snode *stack;
//struct snode{
//	int data[maxsize];
//	int top1=-1;
//	int top2=maxsize;
//};
//void push(stack p,int item,int tag){//tag判别放前栈还是后栈
//	if(p->top2-p->top1==1){
//		printf("man");return;
//	}
//	if(tag==1){
//		p->data[++(p->top1)]=item;
//	}else{
//		p->data[--(p->top2)]=item;
//	}
//}
////2出栈
//int pop(stack p,int tag){
//	if(tag==1){
//		if(p->top1==-1){
//			return -1;
//		}
//		return p->data[(p->top1)--];
//	}
//	else{
//		if(p->top2==maxsize){
//				return -1;
//			}
//		return p->data[(p->top2)++];
//	}
//}
//堆链表一样数组通过top判断满链表不用
//队列
//插入和删除"一端"插入端删除
//顺序存储（数组）//链式存储（）
//#include<iostream>
//using namespace std;
//#define maxsize 10
//struct node{
//	int data[maxsize];
//	int rear;//后下标
//	int front;//前下标
//};
//typedef struct node* queue;
//先进先出，后进前出，开局都指向-1，rear指向哪开辟到哪front到哪清空到哪
//循环队列：front==rear空或满//解决放法加size或tag，最多放n-1的元素
//怎么实现maxsize下一个下标为0，求余
//1.入队
//void addq(queue p,int item){
//	if((p->rear+1)%maxsize==p->front){
//		printf("man");
//		return;
//	}
//	p->rear=(p->rear+1)%maxsize;
//	p->data[p->rear]=item;
//}
//队的链表，front做删除操作而单链表所以只能在头，链表的末尾做删除不行
//相似双链表结构只不过front和rear都等于首尾元素（不同于双链表结构中只有tail是等于），节点结构只有next
//链表思路：temp链表（值的坐拥），指针链表（传递地址作用）
//若用函数（指针链表）（起指引作用）用函数（需改变指引节点P）
//例如：attach(a,b,&p),用二级指针**p
//多项式相加相乘案例

//树
//层次关系（层次管理效率高）
//主要涉及“插入”“删除”“查找”
//查找
//静态
//记录是固定的没有插入和删除
//动态
//有插入和删除

//静态查找
//1顺序查找
//哨兵：可以在数组边界设一个值退出循环
//#include<iostream>
//using namespace std;
//typedef struct node* list;
//struct node{
//	int data[11];//0位置为哨兵，数据放在1-10；
//	int len;
//};
//int search(list tb,int k){
//	int i=0;
//	tb->data[0]=k;//建立哨兵
//	for(i=tb->len;tb->data[i]!=k;i--){//从后查找
//		return i;//！=0找到了
//	}
//}
//2二分查找
//条件：有序存放，连续存放
//int search(list tb,int k){
//	int left,right,mid;
//	left=1;
//	right=tb->len;
//	while(left<=right){
//		mid=(left+right)/2;
//		if(k<tb->data[mid]){
//			right=mid-1;
//		}
//		else if(k>tb->data[mid]){
//			left=mid+1;
//		}
//		else{
//			return mid;
//		}
//	}
//	return -1;
//}
//形成判定树：n个节点的判定树的深度为log2n+1；
//ASL=深度*个数的和再除元素个数
//n个节点
//根 子树（不相交的集合）
//子树不相交，除根结点外，每个节点只有一个父节点，n-1条边
//术语
//1.节点的度（degree）：节点的子树个数
//2.树的度：树的所有节点中最大的度数
//3.叶节点：度为0的节点
//4.父节点
//5.子节点
//6.兄弟节点：有同一父节点
//7.路径，路径长度（边数）
//8.祖先节点：沿树根到某一节点路径上的所有节点都是这个节点的祖先节点
//9.子孙节点：某一结点的子树中所有节点
//10.结点的层次：根节点在第一层
//11.树的深度：树中所有节点中的最大层次
//树的表示
//儿子-兄弟表示法（让其中一个子节点指向下一个兄弟）：儿子数不同
//用二叉树链表实现
//二叉树T定义
//有穷的集合节点，若不为空，有根节点和Tl和Tr组成，左右顺序之分
//斜二叉树：一边
//完美二叉树：满
//完全二叉树：从上到下，从左往右满
//性质
//第i层最大节点2^n-1个
//深度为k的二叉树最大节点总数(2^k)-1
//对任何非空二叉树T，若n0表示叶节点个数，n2是度为2的非叶节点个数，那么两者关系满族n0=n2+1;
//操作
//1.判断是否为空
//2.遍历
//常用遍历放法有四种
//1.先序：根->左子树->右子树
//2.中序：左子树根右子树
//3.后序：左子树右子树根
//4.层次遍历：从上到下，从左往右
//3.创建
//数组
//完全二叉树父子关系：
//1.非根节点的父节点序号i/2
//左子2i<=n,右子2i+1>=n
//一般二叉树若用数组法造成浪费
//链表
//二叉树的存储
//#include<iostream>
//using namespace std;
//typedef struct treenode *bintree;
//typedef bintree position;
//struct treenode{
//	int data;
//	bintree left;
//	bintree right;
//};
////二叉树的遍历
////先序遍历(root->left->right)
//void bianli(bintree bt)
//{
//	if(bt){
//		printf("%d",bt->data);
//		bianli(bt->left);//返回是返回到上一层//因为最后一层为真，再下一层为假，所以返回到最后一层，后续操作按本层形参整体带入
//		//中序：printf("%d",bt->data);(left->root->right)
//		bianli(bt->right);
//		//后序：printf("%d",bt->data);(left->right->root)
//	}
//}
//利用堆栈使递归变成非递归
//中序非递归算法
//#include<iostream>
//#define maxsize 10
//using namespace std;
//typedef struct treenode *bintree;
//typedef struct stack1* stack;
//typedef bintree position;
//struct treenode{
//	int data;
//	bintree left;
//	bintree right;
//};
//struct stack1{
//	bintree data[maxsize];
//	int top;
//};
//stack creat(){
//	stack l=(stack)malloc(sizeof(struct stack1));//前指本身类型后指申请内存存放的数据类型
//	if(l== NULL){
//	    cout << "内存分配失败!" << endl;
//	    exit(1);
//	    }
//	l->top=-1;
//	return l;
//}
//bool isempty(stack s){
//	if(s->top==-1){
//		return true;
//	}
//	return false;
//}
//void push(stack s,bintree t){
//	if(s->top==maxsize-1){
//		return;
//	}
//	else{
//		s->data[++(s->top)]=t;
//	}
//}
//bintree pop(stack s){
//	if(isempty(s)){
//	    cout << "栈为空!" << endl;
//        return NULL;
//	    }
//    return s->data[(s->top)--];
//}
//void bianli(bintree bt){
//	bintree t=bt;
//	stack s=creat();
//	while(t||!isempty(s)){
//		while(t){
//			push(s,t);
//			t=t->left;
//		}
//		if(!isempty(s)){
//			t=pop(s);
//			printf("%5d",t->data);
//			t=t->right;
//		}
//	}
//}
//bintree newTreeNode(int data){
//    bintree node = new treenode;
//    node->data = data;
//    node->left = NULL;
//    node->right = NULL;
//    return node;
//}
//
//// 测试函数
//void test(){
//    // 创建测试树
//    //       1
//    //      / \
//    //     2   3
//    //    / \
//    //   4   5
//    bintree root = newTreeNode(1);
//    root->left = newTreeNode(2);
//    root->right = newTreeNode(3);
//    root->left->left = newTreeNode(4);
//    root->left->right = newTreeNode(5);
//    
//    cout << "中序遍历结果: ";
//    bianli(root);
//    // 释放内存（简化版本，实际使用时需要完整的释放函数）
//    delete root->left->left;
//    delete root->left->right;
//    delete root->left;
//    delete root->right;
//    delete root;
//}
//
//int main(){
//    test();
//    return 0;
//}
//先序遍历
//放在push后（本质第一次碰到就输出）
//层序遍历
//二叉树遍历的核心问题：二维结构线性化
//从节点访问其左右儿子
//访问左儿子后，右儿子节点怎么办
//    所以需要一个存储结构保存暂时不访问的节点
//	  存储结构队列，栈
//队列实现
//一层一层（同层从左到右）
//#include<iostream>
//#define maxsize 10
//using namespace std;
//typedef struct treenode* bintree;
//typedef struct node* queue;
//struct treenode{
//	int data;
//	bintree left;
//	bintree right;
//};
//bintree newTreeNode(int a){
//	bintree bt=new treenode;
//	bt->data=a;
//	bt->left=NULL;
//	bt->right=NULL;
//	return bt;
//}
//struct node{
//	int front;
//	int rear;
//	bintree data[maxsize];
//};
//queue creatqueue(){
//	queue q=new node;
//	q->front=-1;
//	q->rear=-1;
//	return q;
//}
//void addq(queue q,bintree bt){
//	if((q->rear+1)%maxsize==q->front){//用n-1法判断队满
//		printf("man");return;
//	}
//	q->rear=(q->rear+1)%maxsize;
//	q->data[q->rear]=bt;
//}
//bintree deleteq(queue q){
//	if(q->front==q->rear){
//		printf("kong");return NULL;
//	}
//	q->front=(q->front+1)%maxsize;
//	bintree t=q->data[q->front];
//	return t;
//}
//void bianli(bintree bt){
//	queue q;
//	bintree t;
//	if(!bt) return;
//	q=creatqueue();
//	addq(q,bt);
//	while(q->front!=q->rear){
//		t=deleteq(q);
//		printf("%5d",t->data);
//		if(t->left) addq(q,t->left);
//		if(t->right) addq(q,t->right);
//	}
//}
//void test(){
//    // 创建测试树
//    //       1
//    //      / \
//    //     2   3
//    //    / \
//    //   4   5
//    bintree root = newTreeNode(1);
//    root->left = newTreeNode(2);
//    root->right = newTreeNode(3);
//    root->left->left = newTreeNode(4);
//    root->left->right = newTreeNode(5);
//    
//    cout << "层序遍历结果: ";
//    bianli(root);
//    // 释放内存（简化版本，实际使用时需要完整的释放函数）
//    delete root->left->left;
//    delete root->left->right;
//    delete root->left;
//    delete root->right;
//    delete root;
//}
//
//int main(){
//    test();
//    return 0;
//}
//求叶节点
//void bianli(bintree bt)
//{
//	if(!bt->left&&!bt->right){
//		printf("%d",bt->data);
//		bianli(bt->left);//返回是返回到上一层//因为最后一层为真，再下一层为假，所以返回到最后一层，后续操作按本层形参整体带入
//		//中序：printf("%d",bt->data);(left->root->right)
//		bianli(bt->right);
//		//后序：printf("%d",bt->data);(left->right->root)
//	}
//}
//求二叉树高度
//int treeh(bintree bt){
//	int hl,hr,maxh;
//	if(bt){
//		hl=treeh(bt->left);
//		hr=treeh(bt->right);
//		maxh=(hl>hr)?hl:hr;
//		return maxh+1;
//	}
//	else return 0;
//}
//二元运算表达式树（叶节点数其他父节点运算符号）及其遍历
//先序和中序遍历序列来确定一颗二叉树
//根据先序遍历序列第一个节点确定根节点
//根据根节点在中序遍历序列中分割出的左右两个子序列
//对左子树和右子树分别递归使用相同方法继续分解
//例：
//见图1
//同构树（通过若干次子节点交换左右交换相等）
//结构数组表示二叉树
//#include<iostream>
//using namespace std;
//
//#define maxsize 10
//#define tree int
//#define null -1
//
//struct treenode{
//    char data;
//    tree left;
//    tree right;
//}t1[maxsize], t2[maxsize];
//
//tree buildtree(treenode a[]){
//    int n;
//    cin >> n;
//    tree root = null;
//    
//    if(n > 0 && n <= maxsize){
//        bool check[maxsize] = {false};  // 标记节点是否有父节点
//        
//        for(int i = 0; i < n; i++){
//            char left, right;
//            cin >> a[i].data >> left >> right;
//            
//            // 处理左右孩子
//            if(left != '-'){
//                a[i].left = left - '0';  // 字符转数字
//                if(a[i].left >= 0 && a[i].left < n){
//                    check[a[i].left] = true;
//                }
//            } else {
//                a[i].left = null;
//            }
//            
//            if(right != '-'){
//                a[i].right = right - '0';
//                if(a[i].right >= 0 && a[i].right < n){
//                    check[a[i].right] = true;
//                }
//            } else {
//                a[i].right = null;
//            }
//        }
//        
//        // 寻找根节点（没有父节点的节点）
//        for(int i = 0; i < n; i++){
//            if(!check[i]){
//                root = i;
//                break;
//            }
//        }
//    }
//    return root;
//}
//
//// 前序遍历
//void preorderPrint(treenode a[], int root){
//    if(root == null) return;
//    
//    cout << a[root].data << " ";
//    preorderPrint(a, a[root].left);
//    preorderPrint(a, a[root].right);
//}
//
//// 中序遍历
//void inorderPrint(treenode a[], int root){
//    if(root == null) return;
//    
//    inorderPrint(a, a[root].left);
//    cout << a[root].data << " ";
//    inorderPrint(a, a[root].right);
//}
//
//// 后序遍历
//void postorderPrint(treenode a[], int root){
//    if(root == null) return;
//    
//    postorderPrint(a, a[root].left);
//    postorderPrint(a, a[root].right);
//    cout << a[root].data << " ";
//}
//
//int main(){
//    cout << "构建第一棵树：" << endl;
//    tree root1 = buildtree(t1);
//    
//    if(root1 == null){
//        cout << "空树！" << endl;
//    } else {
//        cout << "\n前序遍历: ";
//        preorderPrint(t1, root1);
//        cout << "\n中序遍历: ";
//        inorderPrint(t1, root1);
//        cout << "\n后序遍历: ";
//        postorderPrint(t1, root1);
//        cout << endl;
//    }
//    
//    return 0;
//}

//第四讲二叉搜索树
//静态查找与动态查找
//静态查找：二分法
//动态查找：二叉搜索树（二叉排序树，二叉查找树）
//1.非空左子树的所有键值小于其根节点的键值
//2.非空右子树所有的键值大于其根节点的键值
//3.左右子树都是二叉搜索树
//操作：查找元素x并返回其地址，最小最大，插入删除
//#include<iostream>
//using namespace std;
//typedef struct treenode* treebin;
//typedef treebin position;
//struct treenode{
//	int data;
//	treebin left;
//	treebin right;
//}; 
//二叉搜索树的查找find操作
//position find(int x,treebin bst){
//	if(!bst) return NULL;
//	if(x>bst->data){
//		find(x,bst->right);
//	}
//	else if(x<bst->data){
//		find(x,bst->left);
//	}
//	else{
//		return bst;
//	}
//}//由于非递归函数的执行效率高，可将“尾递归”函数改为迭代函数
//查找的效率对应树的高度
//position find(int x,treebin bst){
//	while(bst){
//		if(bst->data>x){
//			bst=bst->left;
//		}
//		else if(bst->data<x){
//			bst=bst->right;
//		}
//		else{
//			return bst;
//		}
//	}
//	return NULL;
//}//迭代法
////最大最小就是一路向左/想右
////二叉搜索树的插入
//treebin insert(int x,treebin bst){
//	if(!bst){
//		bst=(treebin)malloc(sizeof(struct treenode));
//		bst->data=x;
//		bst->left=bst->right=NULL;
//	}else{
//		if(x<bst->data){
//			bst->left=insert(x,bst->left);
//		}
//		else if(x>bst->data){
//			bst->right=insert(x,bst->right);
//		}
//	}
//	return bst;
//}
//position findmin(treebin a){
//	while(a->left!=NULL){
//		a=a->left;
//	}
//	return a;
//}
////二叉树的删除
////删除叶节点 简单
////删除一个儿子的节点 直接连上爷孙
////删除两个儿子的节点 左子树找最大值做父节点或右子树找最小值作节点
////左子树的最右边，右子树的最左百年
//treebin nodedelete(int x,treebin bst){
//	position temp;
//	if(!bst) printf("weizhaodao");
//	else if(x<bst->data){
//		bst->left=nodedelete(x,bst->left);
//	}
//	else if(x>bst->data){
//		bst->right=nodedelete(x,bst->right);
//	}
//	else{
//		if(bst->left&&bst->right){
//			temp=findmin(bst->right);
//			bst->data=temp->data;//已经改节点了
//			bst->right=nodedelete(bst->data,bst->right);
//		}
//		else{
//			temp=bst;;
//			if(!bst->left){
//				bst=bst->right;
//			}
//			else{
//				bst=bst->left;
//			}
//			free(temp);
//		}
//	}
//	return bst;
//}
//思路两个if锁定目标判断吗双子还是单子或空双子（找右最小替代（用temp）再用单子略指针）
//return在最后，挨个深度连节，最前面未满（到了最深）
//平衡二叉树
//平衡因子：BT=hl-hr分别表示左右子树高度
//AVL |BT|<=1（每一层）
//平衡二叉树最少节点数规律见图二
//平衡二叉树的调整（为了继续平衡）
//rr ll rl lr旋转
//找被破坏点与插入节点方位
//用公式找到新的根节点，再用公式微调即可
//案例：二叉搜索树
//#include <stdio.h>
//#include <stdlib.h>
//
//// 定义AVL树节点结构
//typedef struct AVLNode {
//    int data;
//    int height;
//    struct AVLNode *left;
//    struct AVLNode *right;
//} AVLNode;
//
//// 获取节点高度
//int getHeight(AVLNode *node) {
//    if (node == NULL)
//        return 0;
//    return node->height;
//}
//
//// 获取平衡因子
//int getBalanceFactor(AVLNode *node) {
//    if (node == NULL)
//        return 0;
//    return getHeight(node->left) - getHeight(node->right);
//}
//
//// 更新节点高度
//void updateHeight(AVLNode *node) {
//    if (node == NULL)
//        return;
//    int leftHeight = getHeight(node->left);
//    int rightHeight = getHeight(node->right);
//    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
//}
//
//// 创建新节点
//AVLNode* createNode(int data) {
//    AVLNode *newNode = (AVLNode*)malloc(sizeof(AVLNode));
//    newNode->data = data;
//    newNode->height = 1;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// 1. LL旋转（右旋）
//AVLNode* rightRotate(AVLNode *y) {
//    AVLNode *x = y->left;
//    AVLNode *T2 = x->right;
//    
//    // 执行旋转
//    x->right = y;
//    y->left = T2;
//    
//    // 更新高度
//    updateHeight(y);
//    updateHeight(x);
//    
//    return x; // 返回新的根节点
//}
//
//// 2. RR旋转（左旋）
//AVLNode* leftRotate(AVLNode *x) {
//    AVLNode *y = x->right;
//    AVLNode *T2 = y->left;
//    
//    // 执行旋转
//    y->left = x;
//    x->right = T2;
//    
//    // 更新高度
//    updateHeight(x);
//    updateHeight(y);
//    
//    return y; // 返回新的根节点
//}
//
//// 3. LR旋转（先左旋再右旋）
//AVLNode* leftRightRotate(AVLNode *z) {
//    // 先对左子树进行左旋
//    z->left = leftRotate(z->left);
//    // 再对根节点进行右旋
//    return rightRotate(z);
//}
//
//// 4. RL旋转（先右旋再左旋）
//AVLNode* rightLeftRotate(AVLNode *z) {
//    // 先对右子树进行右旋
//    z->right = rightRotate(z->right);
//    // 再对根节点进行左旋
//    return leftRotate(z);
//}
//
//// 平衡节点
//AVLNode* balanceNode(AVLNode *node) {
//    if (node == NULL)
//        return node;
//    
//    updateHeight(node);
//    int balance = getBalanceFactor(node);
//    
//    // LL情况
//    if (balance > 1 && getBalanceFactor(node->left) >= 0)
//        return rightRotate(node);
//    
//    // RR情况
//    if (balance < -1 && getBalanceFactor(node->right) <= 0)
//        return leftRotate(node);
//    
//    // LR情况
//    if (balance > 1 && getBalanceFactor(node->left) < 0)
//        return leftRightRotate(node);
//    
//    // RL情况
//    if (balance < -1 && getBalanceFactor(node->right) > 0)
//        return rightLeftRotate(node);
//    
//    return node;
//}
//
//// 插入节点
//AVLNode* insert(AVLNode *node, int data) {
//    // 1. 标准的BST插入
//    if (node == NULL)
//        return createNode(data);
//    
//    if (data < node->data)
//        node->left = insert(node->left, data);
//    else if (data > node->data)
//        node->right = insert(node->right, data);
//    else
//        return node; // 不允许重复值
//    
//    // 2. 更新高度并平衡
//    return balanceNode(node);
//}
//
//// 中序遍历
//void inOrderTraversal(AVLNode *root) {
//    if (root != NULL) {
//        inOrderTraversal(root->left);
//        printf("%d ", root->data);
//        inOrderTraversal(root->right);
//    }
//}
//
//// 前序遍历
//void preOrderTraversal(AVLNode *root) {
//    if (root != NULL) {
//        printf("%d ", root->data);
//        preOrderTraversal(root->left);
//        preOrderTraversal(root->right);
//    }
//}
//
//// 释放树的内存
//void freeTree(AVLNode *root) {
//    if (root != NULL) {
//        freeTree(root->left);
//        freeTree(root->right);
//        free(root);
//    }
//}
//
//// 测试函数
//int main() {
//    AVLNode *root = NULL;
//    
//    // 测试LL旋转
//    printf("测试LL旋转:\n");
//    root = insert(root, 30);
//    root = insert(root, 20);
//    root = insert(root, 10);
//    
//    printf("中序遍历: ");
//    inOrderTraversal(root);
//    printf("\n前序遍历: ");
//    preOrderTraversal(root);
//    printf("\n\n");
//    
//    freeTree(root);
//    root = NULL;
//    
//    // 测试RR旋转
//    printf("测试RR旋转:\n");
//    root = insert(root, 10);
//    root = insert(root, 20);
//    root = insert(root, 30);
//    
//    printf("中序遍历: ");
//    inOrderTraversal(root);
//    printf("\n前序遍历: ");
//    preOrderTraversal(root);
//    printf("\n\n");
//    
//    freeTree(root);
//    root = NULL;
//    
//    // 测试LR旋转
//    printf("测试LR旋转:\n");
//    root = insert(root, 30);
//    root = insert(root, 10);
//    root = insert(root, 20);
//    
//    printf("中序遍历: ");
//    inOrderTraversal(root);
//    printf("\n前序遍历: ");
//    preOrderTraversal(root);
//    printf("\n\n");
//    
//    freeTree(root);
//    root = NULL;
//    
//    // 测试RL旋转
//    printf("测试RL旋转:\n");
//    root = insert(root, 10);
//    root = insert(root, 30);
//    root = insert(root, 20);
//    
//    printf("中序遍历: ");
//    inOrderTraversal(root);
//    printf("\n前序遍历: ");
//    preOrderTraversal(root);
//    printf("\n");
//    
//    freeTree(root);
//    
//    return 0;
//}
//怎样判断两个搜索树一不一致
//思路：
//#include<bits/stdc++.h>
//using namespace std;
////1.搜索树的表示
////在原有data left right基础上多+flag（指示是否经过，若后续输入某一data经历flag=0则两搜索树不同）
//typedef struct treenode *tree;
//struct treenode {
//	int data;
//	tree left,right;
//	int flag;
//};
////2.建立搜索树
////读入节点个数建树
//tree creattree(int x){
//	tree temp=new treenode;
//	temp->data=x;
//	temp->left=temp->right=NULL;
//	temp->flag=0;
//	return temp;
//}
//tree inserttree(int num,tree root){
//	if(root==NULL){
//		tree temp=creattree(num);
//		return temp;
//	}
//	if(num>root->data) root->right=inserttree(num,root->right);
//	else if(num<root->data) root->left=inserttree(num,root->left);
//	return root;
//}
//tree maketree(int n_fact){
//	tree root;
//	int x;
//	cin>>x;
//	root=creattree(x);
//	for(int i=1;i<n_fact;i++){
//		cin>>x;
//		tree temp=inserttree(x,root);
//	}
//	return root;
//}
////3.判断一序列是否与搜索函数一致
//bool check(tree t,int x){
//	if(t->flag){
//		if(x>t->data) return check(t->right,x);
//		else if(x<t->data) return check(t->left,x);	
//		else return false;
//	}
//	else{
//		if(x==t->data){
//			t->flag=1;
//			return true;
//		}
//		return false;
//	}
//	
//}
//bool judge(tree t,int num){
//	int flag=1;
//	for(int i=0;i<num;i++){
//		int temp;
//		cin>>temp;
//		if(flag&&check(t,temp)){
//			continue;
//		} 
//		else{
//			flag=0;
//		}
//	}
//	if(!flag){
//		flag=1;
//		return false;
//	}
//	return true;
//}
//void resettree(tree t){
//	if(t->left) return resettree(t->left);
//	if(t->right) return resettree(t->right);//左右等价而非，非此即彼的关系俩if
//	else{
//		t->flag=0;
//	}
//}
////free
//void freetree(tree t){
//	if(t->left){
//		freetree(t->left);
//	}
//	if(t->right){
//		freetree(t->right);
//	}
//	free(t);
//}
////4程序主框架
//int main(){
//	int n_fact,n_test;
//	cin>>n_fact;
//	tree t;
//	while(n_fact){
//		cin>>n_test;
//		t=maketree(n_fact);
//		for(int i=0;i<n_test;i++){
//			if(judge(t,n_fact)){
//				cout<<"Yes"<<endl;
//			}
//			else{
//				cout<<"No"<<endl;
//			}
//			resettree(t);
//		}
//		freetree(t);
//		cin>>n_fact;
//	}
//	return 0;
//}
//单链表逆转
//new已完成old未完成temp改old记录节点位置
//#include<iostream>
//using namespace std;
//typedef struct node_ori* node;
//struct node_ori{
//	int data;
//	node next;
//};
//node creat_node(int v){
//	node temp=new node_ori;
//	temp->data=v;
//	temp->next=NULL;
//	return temp;
//}
//node reverse_node(node root,int k){
//	int cnt=1;
//	node f=root->next;
//	node old=f->next;
//	while(cnt<k){
//		node temp=old->next;
//		old->next=f;
//		f=old;
//		old=temp;
//		cnt++;
//	}
//	root->next->next=old;
//	return f;
//}
//void print(node root){
//	node temp=root->next;
//	while(temp!=NULL){
//		cout<<temp->data;
//		temp=temp->next;
//	}
//}
//int main(){
//	int n;
//	cin>>n;
//	node root=new node_ori;
//	root->data=-1;
//	root->next=NULL;
//	node temp=root;
//	for(int i=0;i<n;i++){
//		int v;
//		cin>>v;
//		temp->next=creat_node(v);
//		temp=temp->next;
//	}
//	int k;
//	cin>>k;
//	root->next=reverse_node(root,k);
//	print(root);
//	return 0;
//}
//堆
//与堆栈不同
//优先队列：特殊的“队列”，取出的元素顺序是按照元素的有限权（关键字）大小，而不是元素进入队列的先后皮顺序
//完全二叉树表示（从上到下，从左到右）
//出栈能完全排序
//堆的两个特性
//结构性：用数组表示完全二叉树
//有序性：任意节点关键字是其子树所有节点的最大或最小值
//“maxheap（最大堆）”也称“大顶堆”：最大值
//“minheap”
//主要操作
//创建
//判断堆满
//插入
//删除
//判断堆空
//返回H中最大元素
//#include<iostream>
//using namespace std;
//typedef struct heap* maxheap;
////创建
//struct heap{
//	int *p;//存储堆元素中的数组
//	int size;
//	int capacity;//堆的最大容量
//};
//maxheap creat(int maxsize){
//	maxheap h=new heap;
//	h->p=(int*)malloc((maxsize+1) * sizeof(int));
//	h->size=0;
//	h->capacity=maxsize;
//	h->p[0]=1000;//定义“哨兵”为大于堆中所有元素可能的的值便于以后更快操作
//	return h;
//}
////插入且保持有序，完全二叉树
//bool isfull(maxheap h){
//	if(h->size==h->capacity){
//		return true;
//	}
//	return false;
//}
//bool isempty(maxheap h){
//	if(h->size==0){
//		return true;
//	}
//	return false;
//}
//void insert(maxheap h,int item){
//	int i;
//	if(isfull(h)){
//		printf("man");
//		return;
//	}
//	i=++h->size;//i指向插入堆后最后一个元素所在位置
//	for(;h->p[i/2]<item&&i>1/*若没有哨兵元素*/;i/=2){
//		h->p[i]=h->p[i/2];//在完全二叉树（*p所形成的//所以并不是完全从大到小）（序号从上到下，从左到右）
//	}//i/2是访问父节点
//	h->p[i]=item;//说明插入的比父节点小即可*****
//}
////从堆中取得键值最大的元素，并删除一个节点
//int deletemax(maxheap h){
//	int p,c;
//	int m,temp;
//	if(isempty(h)){
//		cout<<"kong";
//		exit(0);
//	}
//	m=h->p[1];
//	temp=h->p[h->size--];
//	for(p=1;p*2<=h->size;p=c){//左儿子2i右儿子2i+1
//		c=p*2;//父树的第一子树
//		if((c!=h->size)&&(h->p[c]<h->p[c+1])){
//			c++;
//		}
//		if(temp>=h->p[c]) break;//移动temp到上一层
//		else{
//			h->p[p]=h->p[c];
//		}
//	}
//	h->p[p]=temp;
//	return m;
//}
//int main(){
//	return 0;
//}

//哈夫曼树与哈夫曼编码
//Huffman Tree
//定义：
//带权路径长度（WPL）：设二叉树有n个叶子节点，每个叶子节点带有权值wk
//，从根节点到叶子节点的长度为lk，则每个叶子节点的带权路径长度之和就是：
//WPL=wili++；
//最优二叉树或哈弗曼树：wpl最小的二叉树
//#include<bits/stdc++.h>
//using namespace std;
//typedef struct treenode *huffmantree;
//struct treenode{
//	int weight;//权重
//	huffmantree left,right;
//};
//huffmantree huffman(minheap h){
//	int i;
//	huffmantree t;
//	buildminheap(h);
//	for(i=1;i<h->size;i++){
//		t=new treenode;
//		t->left=deletemin(h);
//		t->right=deletemin(h);
//		t->weight=t->left->weight+t->right->weight;
//		insert(h,t);
//	}
//	t=deletemin(h);
//	return t;
//}//用堆的方法可以自动删除已有父母的节点更简单，而且最小为根
//哈夫曼编码：权重越大编码越简单

//集合的表示
//#include<iostream>
//#define maxsize 30
//using namespace std;
//集合运算：交，并，补，差，判断一个元素是否属于某一集合
//*****并查集：集合并，查某元素属于什么集合
//并查集问题中集合存储如何实现
//并查集集合存储如何实现：
//树结构表示集合，树的每个节点代表一个集合元素
//双亲表示法：孩子指向父亲
//数组形式
//typedef struct{
//	int data;
//	int parent;
//}settype;
//查找某个元素所在集合（用根节点表示）
//int find(settype s[],int x){
//	int i;
//	for(i=0;i<maxsize&&s[i].data!=x;i++);
//	if(i>=maxsize) return -1;
//	for(;s[i].parent>=0;i=s[i].parent);
//	return i;
//}
//集合的并运算
//分别找到x1，x2所在集合树的根节点
//如果不同跟则将其中一个根节点的父结点指针设置成令一根节点的数组下标
//void gether(settype s[],int x1,int x2){
//	int root1=find(s,x1);
//	int root2=find(s,x2);
//	if(root1!=root2) s[root2].parent=root1;
//}
//为了改善合并后的查找性能，将小的集合并到大的集合里去
//根节点的parent为-1，但如果："-"+元素数目表示更多信息
//根节点其实也是元素

//堆中的路径
//案例：将一系列给定的数字插入一个初始为空的小顶堆h[],随后对任意给定的下标i，打印从h[i]到根节点的路径
//#include<iostream>
//#define maxsize 10
//using namespace std;
//typedef struct heap* minheap;
//struct heap{
//	int size;
//	int capacity;
//	int *p;
//};
//minheap creatheap(){
//	minheap temp=new heap;
//	temp->p=(int *)malloc((temp->capacity+1)*sizeof(int));
//	temp->capacity=maxsize;
//	temp->p[0]=-111;
//	temp->size=0;
//	return temp;
//}
//bool isman(minheap h){
//	if(h->size==h->capacity){
//		return true;
//	}
//	return false;
//}
//void insert(minheap h,int data){
//	if(isman(h)){
//		return;
//	}
//	int i=++h->size;
//	for(;data<h->p[i/2];i/=2){
//		h->p[i]=h->p[i/2];
//	}
//	h->p[i]=data;
//}
//void print(int index,minheap h){
//	for(int i=index;i>=1;i/=2){
//		printf("%d",h->p[i]);
//		if(i!=1){
//			printf(" ");
//		}
//	}
//}
//int main(){
//	int f_num,test_num;
//	cin>>f_num>>test_num;
//	minheap root=creatheap();
//	for(int i=0;i<f_num;i++){
//		int data;
//		cin>>data;
//		insert(root,data);
//	}
//	for(int i=1;i<=test_num;i++){
//		int index;
//		cin>>index;
//		print(index,root);
//		if(i!=test_num){
//			cout<<endl;
//		}
//	}
//	return 0;
//}

//案例：file transfer
//不同并查集（普）（含parent data），这个int类型数组唯一数据为parent
//任何有限集合的（n个）元素都可以被一一映射为整数0-n-1
//集合中的每个元素用数组下标去代表
//样例1：
//5
//C 3 2
//I 3 2
//C 1 5
//I 4 5
//I 2 4
//C 3 5
//S
//#include<iostream>
//#define maxsize 30
//using namespace std;
//typedef int settype[maxsize];
////初始化
//void initialization(settype s,int n){
//	for(int i=1;i<=n;i++){
//		s[i]=-1;
//	}
//}
////find
//int find(int index,settype s){
//	if(s[index]<0){
//		return index;
//	}
//	return s[index]=find(s[index],s);
//}
////union
//void Union(int i1,int i2,settype s){
//	int root1=find(i1,s);
//	int root2=find(i2,s);
//	if(s[root1]<s[root2]){
//		s[root1]+=s[root2];
//		s[root2]=root1;
//	}
//	else{
//		s[root2]+=s[root1];
//		s[root1]=root2;
//	}
//}
////cheak
//void check_node(int i2,int i1,settype s){
//	int root1=find(i1,s);
//	int root2=find(i2,s);
//	if(root1!=root2){
//		cout<<"No";
//	}
//	else{
//		cout<<"Yes";
//	}
//}
////check_network
//void check_network(settype s,int n){
//	int num=0;
//	for(int i=1;i<=n;i++){
//		if(s[i]<0){
//			num++;
//		}
//	}
//	if(num==1){
//		cout<<"ok";
//	}
//	else{
//		cout<<"there are "<<num<<" components";
//	}
//}
////主函数
//int main(){
//	settype s;
//	int n;
//	char in;
//	cin>>n;
//	initialization(s,n);
//	do{
//		cin>>in;
//		int s1,s2;
//		cin>>s1>>s2;
//		switch(in){
//			case 'C':
//				check_node(s1,s2,s);break;
//			case 'I':
//				Union(s1,s2,s);break;
//			case 'S':
//				check_network(s,n);break;	
//		}
//	}while(in!='S');
//	return 0;
//}
//按秩归并
//不合理合并树使树越来越高
//应该将矮树并到高树
//s[root]=-树高
//集合登高树高++；
//或按规模归并s[root]=-元素个数

//路径压缩
//对find改变：把路径上的每个节点直接连到根节点

//图（多对多）
//包含：
//一组顶点：V 表示表示顶点集合
//一组边：E 表示边的集合
//           （v,w）边是定点对
//            <v,w>有向边表示从v指向w
//            不考虑重边和自回路
//抽象数据类型定义：
//graph
//数据对象集：G(V,E)非空有限点集和边集
//操作集：
//graph creat()//建立并返回空
//graph insertvertex(graph g,vertex v)
//graph insertedge(graph g,edge e)
//void dfs(graph g,vertex v)：从顶点v出发深度优先遍历图g
//void bfs(graph g,vertex v):从顶点出发宽度优先遍历图g
//void shortestpath(graph g,vertex v,int dist[]):计算图g中顶点v到任意其他顶点的最短距离
//void mst(graph g):计算图g最小生成树
//相关术语：
//无（有）向图：
//带权重的为长度，为网络
//怎样在程序中表示图
//1.邻接矩阵g[n][n] v<i,j>(i，j都为点)有链接为1
//或用长度为n(n+1)/2的一维数组（节省空间）
//二维转一维：公式下表为（i*(i+1)/2+j）
//邻接点（有边直接相连的顶点）
//度：从该点出发的边数为“出度”，指向该点的边数为“入度”
//    无向图：行列非0元素的个数
//    有向图：行非0为出列非0为入
//邻接矩阵
//优点：直观；
//缺点：稀疏图浪费空间时间
//2.邻接表：
//稀疏才核算
//G[n]为指针数组（本质为数组存指针）
//图的遍历
//dfs（深度优先搜索）类似于树的先序遍历
//bfs（广度优先搜索）类似于树的层序遍历 队列
//#include<iostream>
//using namespace std;
//
//int main(){
//	
//	return 0;
//}
//连通：点间存在路径
//回路：起点=终点的路径
//路径：v到w的路径是一系列点的集合，其中任一对相邻的顶点间都有图中的边。
//路径的长度是路径的边数如果带权重就是权重和。。
//如果v到w所有顶点都不同，则称简单路径
//连通图：图中任意两点均连通
//图不连通怎么办：
//连通分量:无向图的极大连通子图
//        极大定点数（再加一个顶点就不连通了），极大边数：包含子图中所有顶点相连的所有边
//强连通：有向图中顶点v和w之间存在双向路径，则称v和w是强连通的
//强连通图：有向图中任意两顶点强连通
//强连通分量：有向图中极大强连通子图
//弱连通：
//弱连通图：连通图但有的不强连通
//每调用一次dfs(v),就把v所在的连通分量便利了一遍。bfs也一样
//如果图中不同连通分量：再用来一个函数从图中未被访问的点调用dfs
//如何建立图
//邻接矩阵表示
//#include<iostream>
//#define weighttype int
//#define maxsize 10
//using namespace std;
//typedef struct gnode* p;
//struct gnode{
//	int v/*点*/,e/*边*/;
//	int g[maxsize][maxsize];
//	//datatype data[maxsize]存顶点数据
//};
//typedef p mgraph;
////creat and 初始化
//typedef int vertex;/*用顶点下标表示顶点，为整形*/
//mgraph creatgraph(int vnum){
//	vertex v,w;
//	mgraph graph;
//	graph=new gnode;
//	graph->v=vnum;
//	graph->e=0;
//	//这里默认顶点编号从0开始，到（graph->v-1）
//	for(v=0;v<graph->v;v++){
//		for(w=0;w<graph->v;w++){
//			graph->g[v][w]=0;
//		}
//	}
//	return graph;
//}
//typedef struct enode *pe;
//struct enode{
//	vertex v1,v2;
//	int weight;
//};
//typedef pe edge;
//void insertedge(mgraph graph,edge e){
//	graph->g[e->v1][e->v2]=e->weight;
//	//若是无向图，还要插入<v2,v1>;
//	graph->g[e->v2][e->v1]=e->weight;
//}
////完整建立一个图
//mgraph buildgraph(){
//	mgraph graph;
//	//第一步：点数+初始化
//	int nv;
//	edge e;
//	vertex v;
//	cin>>nv;
//	graph=creatgraph(nv);
//	//第二步：边数+接收边数据+插入到图中
//	cin>>graph->e;
//	if(graph->e!=0){
//		e=new enode;
//		for(int i=0;i<graph->e;i++){
//			cin>>e->v1>>e->v2>>e->weight;
//			insertedge(graph,e);
//		}
//	}
//	//第三步：如果顶点有数据的话，读入数据
////	for(v=0;v<graph->v;v++){
////		cin>>graph->data[v];
////	}
//	return graph;
//}
//int g1[maxsize][maxsize],nv,ne;
//void buildgraph1(){
//	int i,j,v1,v2,w;
//	cin>>nv;
//	for(i=0;i<nv;i++){
//		for(j=0;j<nv;j++){
//			g1[i][j]=0;
//		}
//	}
//	cin>>ne;
//	for(i=0;i<ne;i++){
//		cin>>v1>>v2>>w;
//		g1[v1][v2]=w;
//		g2[v2][v1]=w;
//	}
//}
//int main(){
//	int v,e;
//	weighttype a[v][v];
//	
//	return 0;
//}
//用邻接表表示图
//邻接表：g[n]为指针数组，对应矩阵每行一个链表，只存非0元素
#include<iostream>
#define maxsize 10
using namespace std;
typedef struct gnode* p;
typedef struct adjnode* p1;
typedef p lgraph;
struct adjnode{
	int adjv;//下标who
	int weight;//长度
	p1 next;//方向
};
typedef struct vnode{
	p1 firstedge;
	//int data//顶点数据
}adjlist[maxsize];//指针数组
struct gnode{
	int nv;//点数
	int ne;//边数
	adjlist g;//顶点//结构体数组
};
//lgraph初始化
typedef int vertex;
lgraph creatgraph(int vnum){
	vertex v,w;
	lgraph graph;
	graph=new gnode;
	graph->nv=vnum;
	graph->ne=0;
	for(v=0;v<graph->nv;v++){
		graph->g[v].firstedge=NULL;
	}
	return graph;
}
//向lgraph插入边
struct enode{
	int weight;
	int v1,v2;
};
typedef struct enode* edge;
void inseredge(lgraph graph,edge e){//插入的都是直接相连
	p1 newnode;
	newnode=new adjnode;
	//v2建立新的连接点
	newnode->adjv=e->v2;
	newnode->weight=e->weight;
	//将v2插入v1表头
	newnode->next=graph->g[e->v1].firstedge;
	graph->g[e->v1].firstedge=newnode;
	//若是无向图<v2,v1>
	//为v1建立新结点
	newnode=new adjnode;
	newnode->adjv=e->v1;
	newnode->weight=e->weight;
	newnode->next=graph->g[e->v2].firstedge;
	graph->g[e->v2].firstedge=newnode;
}
//深度优先搜索******
// 深度优先搜索函数
void DFS(lgraph graph, int v, bool visited[]) {
    // 访问顶点v
    cout << "访问顶点: " << v << endl;
    visited[v] = true;
    
    // 遍历v的所有邻接点
    p1 p = graph->g[v].firstedge;
    while (p != NULL) {
        int w = p->adjv;
        if (!visited[w]) {
            DFS(graph, w, visited);
        }
        p = p->next;
    }
}

// 深度优先遍历主函数（用于整个图的DFS）
void DFSTraverse(lgraph graph) {
    if (graph == NULL || graph->nv == 0) {
        cout << "图为空或没有顶点" << endl;
        return;
    }
    
    // 创建访问标记数组
    bool *visited = new bool[graph->nv];//第一次见
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = false;
    }
    
    cout << "深度优先遍历结果：" << endl;
    
    // 对每个未访问的顶点进行DFS
    for (int v = 0; v < graph->nv; v++) {
        if (!visited[v]) {
            DFS(graph, v, visited);
        }
    }
    
    delete[] visited;
}//全部

// 可选：从指定顶点开始的DFS
void DFSFromVertex(lgraph graph, int startVertex) {
    if (graph == NULL || graph->nv == 0) {
        cout << "图为空或没有顶点" << endl;
        return;
    }
    
    if (startVertex < 0 || startVertex >= graph->nv) {
        cout << "起始顶点不存在" << endl;
        return;
    }
    
    // 创建访问标记数组
    bool *visited = new bool[graph->nv];
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = false;
    }
    
    cout << "从顶点 " << startVertex << " 开始的深度优先遍历：" << endl;
    DFS(graph, startVertex, visited);
    
    // 检查是否有未访问的顶点（非连通图的情况）
    bool allVisited = true;
    for (int i = 0; i < graph->nv; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }
    
    if (!allVisited) {
        cout << "\n注意：图是非连通的，还有顶点未访问" << endl;
    }
    
    delete[] visited;
}
// 广度优先搜索函数//类似层序遍历
void BFS(lgraph graph, int startVertex) {
    if (graph == NULL || graph->nv == 0) {
        cout << "图为空或没有顶点" << endl;
        return;
    }
    
    if (startVertex < 0 || startVertex >= graph->nv) {
        cout << "起始顶点不存在" << endl;
        return;
    }
    
    // 创建访问标记数组
    bool *visited = new bool[graph->nv];
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = false;
    }
    
    // 创建队列
    int queue[maxsize];
    int front = 0, rear = 0;
    
    // 访问起始顶点并入队
    cout << "访问顶点: " << startVertex << endl;
    visited[startVertex] = true;
    queue[rear++] = startVertex;
    
    cout << "广度优先遍历顺序：";
    
    while (front != rear) {
        // 出队
        int currentVertex = queue[front++];
        cout << currentVertex << " ";
        
        // 遍历当前顶点的所有邻接点
        p1 p = graph->g[currentVertex].firstedge;
        while (p != NULL) {
            int adjVertex = p->adjv;
            if (!visited[adjVertex]) {
                // 访问邻接点并入队
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            p = p->next;
        }
    }
    
    // 检查是否有未访问的顶点（非连通图的情况）
    bool allVisited = true;
    for (int i = 0; i < graph->nv; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }
    
    if (!allVisited) {
        cout << "\n注意：图是非连通的，还有顶点未访问" << endl;
    }
    
    delete[] visited;
}

// 整个图的广度优先遍历
void BFSTraverse(lgraph graph) {
    if (graph == NULL || graph->nv == 0) {
        cout << "图为空或没有顶点" << endl;
        return;
    }
    
    // 创建访问标记数组
    bool *visited = new bool[graph->nv];
    for (int i = 0; i < graph->nv; i++) {
        visited[i] = false;
    }
    
    // 创建队列
    int queue[maxsize];
    int front = 0, rear = 0;
    
    cout << "整个图的广度优先遍历：" << endl;
    
    // 对每个未访问的顶点进行BFS
    for (int v = 0; v < graph->nv; v++) {
        if (!visited[v]) {
            cout << "连通分量（从顶点" << v << "开始）: ";
            
            // 访问起始顶点并入队
            visited[v] = true;
            queue[rear++] = v;
            
            while (front != rear) {
                // 出队
                int currentVertex = queue[front++];
                cout << currentVertex << " ";
                
                // 遍历当前顶点的所有邻接点
                p1 p = graph->g[currentVertex].firstedge;
                while (p != NULL) {
                    int adjVertex = p->adjv;
                    if (!visited[adjVertex]) {
                        // 访问邻接点并入队
                        visited[adjVertex] = true;
                        queue[rear++] = adjVertex;
                    }
                    p = p->next;
                }
            }
            cout << endl;
        }
    }
    
    delete[] visited;
}

// BFS查找最短路径（未加权图的最短路径）
void BFSShortestPath(lgraph graph, int startVertex, int endVertex) {
    if (graph == NULL || graph->nv == 0) {
        cout << "图为空或没有顶点" << endl;
        return;
    }
    
    if (startVertex < 0 || startVertex >= graph->nv || 
        endVertex < 0 || endVertex >= graph->nv) {
        cout << "顶点不存在" << endl;
        return;
    }
    
    if (startVertex == endVertex) {
        cout << "起始顶点和结束顶点相同，距离为0" << endl;
        return;
    }
    
    // 创建访问标记数组
    int *distance = new int[graph->nv];  // 记录从起点到每个顶点的距离
    int *predecessor = new int[graph->nv];  // 记录前驱顶点
    
    for (int i = 0; i < graph->nv; i++) {
        distance[i] = -1;  // -1表示不可达
        predecessor[i] = -1;
    }
    
    // 创建队列
    int queue[maxsize];
    int front = 0, rear = 0;
    
    // 起始顶点
    distance[startVertex] = 0;
    queue[rear++] = startVertex;
    
    bool found = false;
    
    while (front != rear && !found) {
        // 出队
        int currentVertex = queue[front++];
        
        // 遍历当前顶点的所有邻接点
        p1 p = graph->g[currentVertex].firstedge;
        while (p != NULL && !found) {
            int adjVertex = p->adjv;
            if (distance[adjVertex]<0) {
                // 访问邻接点
                distance[adjVertex] = distance[currentVertex] + 1;
                predecessor[adjVertex] = currentVertex;
                queue[rear++] = adjVertex;
                
                // 检查是否到达目标顶点
                if (adjVertex == endVertex) {
                    found = true;
                }
            }
            p = p->next;
        }
    }
    
    // 输出结果
    if (found) {
        cout << "顶点" << startVertex << "到顶点" << endVertex << "的最短距离: " 
             << distance[endVertex] << endl;
        
        // 输出路径
        cout << "最短路径: ";
        int path[maxsize];
        int pathLength = 0;
        int current = endVertex;
        
        while (current != -1) {
            path[pathLength++] = current;
            current = predecessor[current];
        }
        
        // 反向输出路径
        for (int i = pathLength - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "顶点" << startVertex << "到顶点" << endVertex << "不可达" << endl;
    }
    
    delete[] distance;
    delete[] predecessor;
}
int main() {
    // 创建图
    lgraph graph = creatgraph(5);
    
    // 创建边并插入
    edge e1 = new enode;
    e1->v1 = 0; e1->v2 = 1; e1->weight = 10;
    inseredge(graph, e1);
    
    edge e2 = new enode;
    e2->v1 = 0; e2->v2 = 3; e2->weight = 20;
    inseredge(graph, e2);
    
    edge e3 = new enode;
    e3->v1 = 1; e3->v2 = 2; e3->weight = 30;
    inseredge(graph, e3);
    
    edge e4 = new enode;
    e4->v1 = 2; e4->v2 = 4; e4->weight = 40;
    inseredge(graph, e4);
    
    // 深度优先遍历
    cout << "=== 整个图的DFS ===" << endl;
    DFSTraverse(graph);
    
    cout << "\n=== 从顶点1开始的DFS ===" << endl;
    DFSFromVertex(graph, 1);
    
    // 清理内存
    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete graph;
    
    return 0;
}
//邻接矩阵的dfs和bfs
#include<iostream>
#include<queue>  // 用于BFS的队列
#define MAXSIZE 10
using namespace std;

// 邻接矩阵图结构
typedef struct MGraph {
    int edges[MAXSIZE][MAXSIZE];  // 邻接矩阵
    int n;  // 顶点数
    int e;  // 边数
    // int vex[MAXSIZE];  // 顶点信息（可选）
} MGraph;

// 创建邻接矩阵图
MGraph* CreateMGraph(int n) {
    MGraph* G = new MGraph;
    G->n = n;
    G->e = 0;
    
    // 初始化邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            G->edges[i][j] = 0;  // 0表示无边，有权图可以用INF
        }
    }
    return G;
}

// 向邻接矩阵图中插入边（无向图）
void InsertEdge(MGraph* G, int v1, int v2, int weight) {
    if (G == NULL || v1 < 0 || v1 >= G->n || v2 < 0 || v2 >= G->n) {
        return;
    }
    
    // 插入边
    G->edges[v1][v2] = weight;
    G->edges[v2][v1] = weight;  // 无向图对称
    G->e++;
}

// ========== DFS 深度优先搜索 ==========

// DFS递归辅助函数
void DFS(MGraph* G, int v, bool visited[]) {
    // 访问顶点v
    cout << v << " ";
    visited[v] = true;
    
    // 递归访问v的所有未访问邻接点
    for (int w = 0; w < G->n; w++) {
        if (G->edges[v][w] != 0 && !visited[w]) {  // 有边且未访问
            DFS(G, w, visited);
        }
    }
}

// 深度优先遍历（从指定顶点开始）
void DFSTraverseFrom(MGraph* G, int start) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    if (start < 0 || start >= G->n) {
        cout << "起始顶点无效" << endl;
        return;
    }
    
    // 初始化访问标记数组
    bool* visited = new bool[G->n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
    }
    
    cout << "从顶点" << start << "开始的DFS: ";
    DFS(G, start, visited);
    cout << endl;
    
    // 检查是否所有顶点都被访问（非连通图）
    bool allVisited = true;
    for (int i = 0; i < G->n; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }
    
    if (!allVisited) {
        cout << "注意：图是非连通图" << endl;
    }
    
    delete[] visited;
}

// 深度优先遍历（遍历整个图，处理非连通图）
void DFSTraverse(MGraph* G) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    // 初始化访问标记数组
    bool* visited = new bool[G->n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
    }
    
    cout << "整个图的DFS遍历: " << endl;
    int component = 1;
    
    for (int i = 0; i < G->n; i++) {
        if (!visited[i]) {
            cout << "连通分量" << component++ << ": ";
            DFS(G, i, visited);
            cout << endl;
        }
    }
    
    delete[] visited;
}

// DFS非递归实现（使用栈）
void DFS_NonRecursive(MGraph* G, int start) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    if (start < 0 || start >= G->n) {
        cout << "起始顶点无效" << endl;
        return;
    }
    
    // 初始化访问标记数组
    bool* visited = new bool[G->n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
    }
    
    // 使用栈
    int stack[MAXSIZE];
    int top = -1;
    
    cout << "非递归DFS从顶点" << start << "开始: ";
    
    // 访问起始顶点并入栈
    cout << start << " ";
    visited[start] = true;
    stack[++top] = start;
    
    while (top != -1) {
        int v = stack[top];  // 查看栈顶元素
        
        // 查找v的未访问邻接点
        int w;
        for (w = 0; w < G->n; w++) {
            if (G->edges[v][w] != 0 && !visited[w]) {
                break;
            }
        }
        
        if (w < G->n) {  // 找到未访问邻接点
            // 访问并入栈
            cout << w << " ";
            visited[w] = true;
            stack[++top] = w;
        } else {  // 没有未访问邻接点，出栈
            top--;
        }
    }
    
    cout << endl;
    delete[] visited;
}

// ========== BFS 广度优先搜索 ==========

// BFS主函数
void BFS(MGraph* G, int start) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    if (start < 0 || start >= G->n) {
        cout << "起始顶点无效" << endl;
        return;
    }
    
    // 初始化访问标记数组
    bool* visited = new bool[G->n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
    }
    
    // 使用队列
    queue<int> q;
    
    cout << "从顶点" << start << "开始的BFS: ";
    
    // 访问起始顶点并入队
    cout << start << " ";
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        // 遍历v的所有邻接点
        for (int w = 0; w < G->n; w++) {
            if (G->edges[v][w] != 0 && !visited[w]) {
                // 访问并入队
                cout << w << " ";
                visited[w] = true;
                q.push(w);
            }
        }
    }
    
    cout << endl;
    
    // 检查是否所有顶点都被访问
    bool allVisited = true;
    for (int i = 0; i < G->n; i++) {
        if (!visited[i]) {
            allVisited = false;
            break;
        }
    }
    
    if (!allVisited) {
        cout << "注意：图是非连通图" << endl;
    }
    
    delete[] visited;
}

// BFS遍历整个图
void BFSTraverse(MGraph* G) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    // 初始化访问标记数组
    bool* visited = new bool[G->n];
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
    }
    
    cout << "整个图的BFS遍历: " << endl;
    int component = 1;
    
    for (int i = 0; i < G->n; i++) {
        if (!visited[i]) {
            cout << "连通分量" << component++ << ": ";
            
            // BFS当前连通分量
            queue<int> q;
            
            // 访问起始顶点
            cout << i << " ";
            visited[i] = true;
            q.push(i);
            
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                
                // 遍历v的所有邻接点
                for (int w = 0; w < G->n; w++) {
                    if (G->edges[v][w] != 0 && !visited[w]) {
                        // 访问并入队
                        cout << w << " ";
                        visited[w] = true;
                        q.push(w);
                    }
                }
            }
            cout << endl;
        }
    }
    
    delete[] visited;
}

// BFS查找最短路径（未加权图）
void BFSShortestPath(MGraph* G, int start, int end) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    if (start < 0 || start >= G->n || end < 0 || end >= G->n) {
        cout << "顶点无效" << endl;
        return;
    }
    
    if (start == end) {
        cout << "起始和结束顶点相同，距离为0" << endl;
        return;
    }
    
    // 初始化数组
    bool* visited = new bool[G->n];
    int* distance = new int[G->n];
    int* predecessor = new int[G->n];
    
    for (int i = 0; i < G->n; i++) {
        visited[i] = false;
        distance[i] = -1;  // -1表示不可达
        predecessor[i] = -1;
    }
    
    // 使用队列
    queue<int> q;
    
    // 初始化起始顶点
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    
    bool found = false;
    
    while (!q.empty() && !found) {
        int v = q.front();
        q.pop();
        
        // 遍历v的所有邻接点
        for (int w = 0; w < G->n; w++) {
            if (G->edges[v][w] != 0 && !visited[w]) {
                // 访问顶点
                visited[w] = true;
                distance[w] = distance[v] + 1;
                predecessor[w] = v;
                q.push(w);
                
                // 检查是否到达目标
                if (w == end) {
                    found = true;
                    break;
                }
            }
        }
    }
    
    // 输出结果
    if (found) {
        cout << "顶点" << start << "到顶点" << end << "的最短距离: " 
             << distance[end] << endl;
        
        // 输出路径
        cout << "最短路径: ";
        int path[MAXSIZE];
        int pathLength = 0;
        int current = end;
        
        while (current != -1) {
            path[pathLength++] = current;
            current = predecessor[current];
        }
        
        // 反向输出
        for (int i = pathLength - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "顶点" << start << "到顶点" << end << "不可达" << endl;
    }
    
    delete[] visited;
    delete[] distance;
    delete[] predecessor;
}

// 打印邻接矩阵
void PrintMGraph(MGraph* G) {
    if (G == NULL || G->n == 0) {
        cout << "图为空" << endl;
        return;
    }
    
    cout << "邻接矩阵 (" << G->n << "个顶点, " << G->e << "条边):" << endl;
    cout << "   ";
    for (int i = 0; i < G->n; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    for (int i = 0; i < G->n; i++) {
        cout << i << ": ";
        for (int j = 0; j < G->n; j++) {
            cout << G->edges[i][j] << " ";
        }
        cout << endl;
    }
}

// 测试函数
int main() {
    // 创建图
    MGraph* G = CreateMGraph(6);
    
    // 添加边
    InsertEdge(G, 0, 1, 1);
    InsertEdge(G, 0, 2, 1);
    InsertEdge(G, 1, 3, 1);
    InsertEdge(G, 2, 3, 1);
    InsertEdge(G, 3, 4, 1);
    InsertEdge(G, 4, 5, 1);
    InsertEdge(G, 1, 4, 1);  // 添加一条捷径
    
    // 打印邻接矩阵
    PrintMGraph(G);
    cout << endl;
    
    // DFS测试
    cout << "=== DFS测试 ===" << endl;
    DFSTraverseFrom(G, 0);
    DFSTraverseFrom(G, 3);
    cout << endl;
    
    DFSTraverse(G);
    cout << endl;
    
    DFS_NonRecursive(G, 0);
    cout << endl;
    
    // BFS测试
    cout << "\n=== BFS测试 ===" << endl;
    BFS(G, 0);
    BFS(G, 3);
    cout << endl;
    
    BFSTraverse(G);
    cout << endl;
    
    // 最短路径测试
    cout << "\n=== 最短路径测试 ===" << endl;
    BFSShortestPath(G, 0, 5);
    BFSShortestPath(G, 0, 3);
    BFSShortestPath(G, 1, 5);
    
    // 清理内存
    delete G;
    
    return 0;
}


























