#include <stdio.h>
#include<iostream>
using namespace std;
const int maxn = 1e5 + 10;

struct Node
{
	int key;        // �ؼ�ֵ
	int data;       // Я��������
	int left;       // ��������ַ�������±꣩
	int right;      // ��������ַ�������±꣩
	int height;     // ��ǰ���Ϊ���������߶�
	void Init() { data = key = left = right = height = -1; }
	void Init(int k_, int d_) { Init(); key = k_; data = d_; }
	Node() { Init(); }
	Node(int k_, int d_ = 0) { Init(k_, d_); }
};

Node tr[maxn];
int root, tp;  // root��Ǹ��ڵ�λ�ã�tpȫ�ֽ������±�

inline int UpdateHeight(int now)
{
	// ���� tr[now] ���������߶ȣ���tr[now].height��ֵ
	
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	int h = (lh > rh ? lh : rh) + 1;
	tr[now].height = h;
	return h;
}
// ���� tr[now] ����ƽ������
inline int getPHYZ(int now)
{
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	return lh - rh;
}
//LL�ͣ���������
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
//RR�ͣ���������
int RR(int an)
{
	/*lnָ��p���������ĸ����
	*lc����������Ϊan��������
	*�����µĸ����ln*/
	int rn = tr[an].right;
	int rln = tr[rn].left;
	tr[rn].left = an;
	tr[an].right = rln;
	UpdateHeight(an);
	UpdateHeight(rn);
	return rn;
}
//LR�ͣ�������������
int LR(int an)
{
	tr[an].left = RR(tr[an].left);
	return LL(an);
}
//RL�ͣ�������������
int RL(int an)
{
	tr[an].right = LL(tr[an].right);
	return RR(an);
}
//���뺯��
void Insert(int& now, int key, int data)
{
	if (now == -1)
	{
		// ����ָ��Ϊ�գ��½���㱣������
		now = ++tp;
		tr[now].Init(key, data);
	}
	// �жϲ����ĸ��������������ݣ��ж�ƽ�����ӣ�����ȷ��ת�����¸߶�
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
//ɾ������
void Delete(int& now, int key)
{
	//������Ϊ�գ�����
	//���keyС�ڵ�ǰ����key,�ڸý����������в���
	//���key���ڵ�ǰ����key,�ڸý����������в���
	//���key���,���ҵ���Ӧ���,ɾ���ý��
	if (now == -1) return;
	else if (key < tr[now].key) Delete(tr[now].left, key);
	else if (key > tr[now].key) Delete(tr[now].right, key);
	else
	{
		// ɾ����ǰ���
		//������ֻ������������ΪҶ�ӽ��,�ý�����Һ��Ӵ���
		//������ֻ������������ý�������Ӵ���
		//���������������Ҳ��������������ת����ת�ң���Ѱ�ҵ����������Ľ��������ý��,Ȼ���ٵݹ�����������Ľ��ɾ��
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
	//���¸߶�
	UpdateHeight(now);
	// ������ƽ��
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
//�ҵ�key��ɾ��
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
		// ɾ����ǰ���
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
	// ������ƽ��
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
//�ҵ���С��key��ɾ��
void find_min_del(int& now) {
	if (tr[now].left != -1) find_min_del(tr[now].left);
	else
	{
		cout << tr[now].data << endl;
		// ɾ����ǰ���
		if (tr[now].left == -1)
			now = tr[now].right;
		else if (tr[now].right == -1)
			now = tr[now].left;
	}
	if (now == -1) return;
	UpdateHeight(now);
	// ������ƽ��
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
//�ҵ�����key��ɾ��
void find_max_del(int& now) {
	if (tr[now].right != -1) find_max_del(tr[now].right);
	else
	{
		cout << tr[now].data << endl;
		// ɾ����ǰ���
		if (tr[now].right == -1)
			now = tr[now].left;
	}
	if (now == -1) return;
	UpdateHeight(now);
	// ������ƽ��
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
	for (root = tp = -1; n--; )  // ��ʼ�������͡��ڴ�ָ�롱
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
