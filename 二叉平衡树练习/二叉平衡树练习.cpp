#include <stdio.h>
#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;

struct Node
{
	int key;        // 关键值
	int data;       // 携带的数据
	int left;       // 左子树地址（数组下标）
	int right;      // 右子树地址（数组下标）
	int height;     // 当前结点为根的子树高度
	void Init() { data = key = left = right = height = -1; }
	void Init(int k_, int d_) { Init(); key = k_; data = d_; }
	Node() { Init(); }
	Node(int k_, int d_ = 0) { Init(k_, d_); }
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline int UpdateHeight(int now)
{
	// 更新 tr[now] 结点的子树高度，即tr[now].height的值
	
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	int h = (lh > rh ? lh : rh) + 1;
	tr[now].height = h;
	return h;
}
// 计算 tr[now] 结点的平衡因子
inline int getPHYZ(int now)
{
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	return lh - rh;
}
//LL型，右旋处理
int LL(int an)
{
	int ln = tr[an].left;
	int lrn = tr[ln].right;
	tr[ln].right = an;
	tr[an].left = lrn;
	UpdateHeight(an);
	UpdateHeight(ln);
	return ln;
}
//RR型，左旋处理
int RR(int an)
{
	/*ln指向p的右子树的根结点
	*lc的左子树挂为an的右子树
	*返回新的根结点ln*/
	int rn = tr[an].right;
	int rln = tr[rn].left;
	tr[rn].left = an;
	tr[an].right = rln;
	UpdateHeight(an);
	UpdateHeight(rn);
	return rn;
}
//LR型，先右旋后左旋
int LR(int an)
{
	tr[an].left = RR(tr[an].left);
	return LL(an);
}
//RL型，先左旋后右旋
int RL(int an)
{
	tr[an].right = LL(tr[an].right);
	return RR(an);
}
//插入函数
void Insert(int& now, int key, int data)
{
	if (now == -1)
	{
		// 传入指针为空，新建结点保存数据
		now = ++tp;
		tr[now].Init(key, data);
	}
	// 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else {
		if (key <= tr[now].key) {
			Insert(tr[now].left, key, data);
			if (getPHYZ(now) == 2) {
				if (key <= tr[tr[now].left].key)
					now = LL(now);
				else
					now = LR(now);
			}
		}
		else if (key > tr[now].key) {
			Insert(tr[now].right, key, data);
			if (getPHYZ(now) == -2) {
				if (key >= tr[tr[now].right].key)
					now = RR(now);
				else now = RL(now);
			}
		}
	}
	UpdateHeight(now);
}
//删除函数
void Delete(int& now, int key)
{
	//如果结点为空，返回
	//如果key小于当前结点的key,在该结点的左子树中查找
	//如果key大于当前结点的key,在该结点的右子树中查找
	//如果key相等,则找到对应结点,删除该结点
	if (now == -1) return;
	else if (key < tr[now].key) Delete(tr[now].left, key);
	else if (key > tr[now].key) Delete(tr[now].right, key);
	else
	{
		// 删除当前结点
		//如果结点只有右子树或者为叶子结点,该结点由右孩子代替
		//如果结点只有左子树，则该结点右左孩子代替
		//如果结点既有右子树也有左子树，则先转左再转右，由寻找到左子树最大的结点来代替该结点,然后再递归把左子树最大的结点删除
		if (tr[now].left == -1)
			now = tr[now].right;
		else if (tr[now].right == -1)
			now = tr[now].left;
		else {
			int next = tr[now].left;
			while (tr[next].right != -1)
				next = tr[next].right;
			tr[now].key = tr[next].key;
			tr[now].data = tr[next].data;
			Delete(tr[now].left, tr[next].key);
		}
	}
	if (now == -1)return;
	//更新高度
	UpdateHeight(now);
	// 处理树平衡
	if (getPHYZ(now) == 2) {
		if (getPHYZ(tr[now].left) >= 0)
			now = LL(now);
		else
			now = LR(now);
	}
	else if (getPHYZ(now) == -2) {
		if (getPHYZ(tr[now].right) <= 0)
			now = RR(now);
		else now = RL(now);
	}
}
//找到key并删除
void find_key_del(int& now, int key) {
	

	if (now == -1) {
		cout << 0 << endl;
		return;
	}
	else if (key < tr[now].key) find_key_del(tr[now].left, key);
	else if (key > tr[now].key) find_key_del(tr[now].right, key);
	else
	{
		cout << tr[now].data << endl;
		// 删除当前结点
		if (tr[now].left == -1)
			now = tr[now].right;
		else if (tr[now].right == -1)
			now = tr[now].left;
		else {
			int next = tr[now].left;
			while (tr[next].right != -1)
				next = tr[next].right;
			tr[now].data = tr[next].data;
			tr[now].key = tr[next].key;
			Delete(tr[now].left, tr[next].key);
		}
	}
	if (now == -1) return;
	UpdateHeight(now);
	// 处理树平衡
	if (getPHYZ(now) == 2) {
		if (getPHYZ(tr[now].left) >= 0)
			now = LL(now);
		else
			now = LR(now);
	}
	else if (getPHYZ(now) == -2) {
		if (getPHYZ(tr[now].right) <= 0)
			now = RR(now);
		else now = RL(now);
	}
}
//找到最小的key并删除
void find_min_del(int& now) {
	if (tr[now].left != -1) find_min_del(tr[now].left);
	else
	{
		cout << tr[now].data << endl;
		// 删除当前结点
		if (tr[now].left == -1)
			now = tr[now].right;
		else if (tr[now].right == -1)
			now = tr[now].left;
	}
	if (now == -1) return;
	UpdateHeight(now);
	// 处理树平衡
	if (getPHYZ(now) == 2) {
		if (getPHYZ(tr[now].left) >= 0)
			now = LL(now);
		else
			now = LR(now);
	}
	else if (getPHYZ(now) == -2) {
		if (getPHYZ(tr[now].right) <= 0)
			now = RR(now);
		else now = RL(now);
	}
	
}
//找到最大的key并删除
void find_max_del(int& now) {
	if (tr[now].right != -1) find_max_del(tr[now].right);
	else
	{
		cout << tr[now].data << endl;
		// 删除当前结点
		if (tr[now].right == -1)
			now = tr[now].left;
	}
	if (now == -1) return;
	UpdateHeight(now);
	// 处理树平衡
	if (getPHYZ(now) == 2) {
		if (getPHYZ(tr[now].left) >= 0)
			now = LL(now);
		else
			now = LR(now);
	}
	else if (getPHYZ(now) == -2) {
		if (getPHYZ(tr[now].right) <= 0)
			now = RR(now);
		else now = RL(now);
	}

}

int main()
{
	int n, op, key, data;
	scanf("%d", &n);
	for (root = tp = -1; n--; )  // 初始化根结点和“内存指针”
	{
		scanf("%d", &op);
		if (op == 1)
		{
			cin >> data >> key;
			Insert(root, key, data);
		}
		else if (op == 2)
		{
			if (root == -1)
				cout << 0 << endl;
			else
				find_max_del(root);
		}
		else if (op == 3)
		{
			if (root == -1)
				cout << 0 << endl;
			else
				find_min_del(root);
		}
		else
		{
			cin >> key;
			find_key_del(root, key);
		}
	}
	return 0;
}
