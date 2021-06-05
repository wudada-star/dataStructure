#include<iostream>
#include<string>
using namespace std;
struct  node
{
	char data;
	node* right;
	node* left;
	node* parent;
	int left_len;	//�ý���������������
	int right_len;	//�������������
	char left_data;		//�������������Ľ��
	char right_data;	//�������������Ľ��
	node(char c) :data(c), right(NULL), left(NULL), right_len(0), left_len(0) {}
	node() {}

};
string str;
int inum;

void maketree(node* now) {

	if (inum < str.length() && str[++inum] != '#') {

		now->left = new node(str[inum]);
		maketree(now->left);
	}
	if (inum < str.length() && str[++inum] != '#') {

		now->right = new node(str[inum]);
		maketree(now->right);
	}
}
	void getlen(node * nt, int& len, char& cc) {
		int l = len, r = len;
		char lc = cc, rc = cc;
		if (nt->left != NULL) {
			l++;
			lc = nt->left->data;
			getlen(nt->left, l, lc);
		}
		if (nt->right != NULL) {
			r++;
			rc = nt->right->data;
			getlen(nt->right, r, rc);
		}
		if (l > r) {
			len = l;
			cc = lc;
		}
		else {
			len = r;
			cc = rc;
		}

	}


	void getans(node * nt) {
		if (nt->left != NULL) {
			nt->left_data = nt->left->data;
			nt->left_len = 1;
			getlen(nt->left, nt->left_len, nt->left_data);
		}
		if (nt->right != NULL) {
			nt->right_data = nt->right->data;
			nt->right_len = 1;
			getlen(nt->right, nt->right_len, nt->right_data);
		}

	}


	void func(node * nt, int& ans, char& lc, char& rc) {
		if (nt == NULL)
			return;
		if (nt->left != NULL || nt->right != NULL) {
			nt->left_data = nt->right_data = nt->data;

			getans(nt);

			if (ans < (nt->left_len + nt->right_len)) {
				ans = nt->left_len + nt->right_len;
				lc = nt->left_data;
				rc = nt->right_data;
			}

			func(nt->left, ans, lc, rc);
			func(nt->right, ans, lc, rc);
		}
	}

	int main() {

		int n;
		cin >> n;
		while (n--)
		{
			cin >> str;
			if (str == "#") {
				cout << "0:" << endl;
				continue;
			}
			node* root = new node(str[0]);
			inum = 0;
			maketree(root);

			int ans = 0;	//��Ľ����ֻ��һ����������Ϊ0
			char max_left = 0;	//�����߽��
			char max_right = 0;
			node* now = root;
			func(now, ans, max_left, max_right);
			if (max_right == 0 && max_left == 0) 
			{
				cout << ans << ":" << endl;
			}
			else
			{
				cout << ans << ":" << max_left << " " << max_right << endl;
			}


		}

		return 0;
	}