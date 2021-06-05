#include <stdio.h>
#include<iostream>
using namespace std;
const int maxn = 1e5 + 5;

int tp = -1, root = -1;

struct Node {
    int key;
    int l, r;
    int h;
    int sum;
    Node() { key = l = r = h = -1; }
    void init(int _key) { key = _key, sum = 1, l = r = h = -1; }
}tr[maxn];

void updateH(int rt) {
    int lh = tr[rt].l == -1 ? 0 : tr[tr[rt].l].h;
    int rh = tr[rt].r == -1 ? 0 : tr[tr[rt].r].h;
    tr[rt].h = (lh > rh ? lh : rh) + 1;
}

//能用其他变量计算出来的尽量不要多设一个变量，否则每次都得更新多一个变量
int getPHYZ(int rt) {
    int lh = tr[rt].l == -1 ? 0 : tr[tr[rt].l].h;
    int rh = tr[rt].r == -1 ? 0 : tr[tr[rt].r].h;
    return lh - rh;
}

void updateSum(int rt) {
    int l = tr[rt].l == -1 ? 0 : tr[tr[rt].l].sum;
    int r = tr[rt].r == -1 ? 0 : tr[tr[rt].r].sum;
    tr[rt].sum = l + r + 1;
}

int LL(int an) {
    int bn = tr[an].l;
    int dn = tr[bn].r;
    tr[bn].r = an;
    tr[an].l = dn;
    updateH(an);
    updateH(bn);
    updateSum(an);
    updateSum(bn);
    return bn;
}

int RR(int an) {
    int bn = tr[an].r;
    int dn = tr[bn].l;
    tr[bn].l = an;
    tr[an].r = dn;
    updateH(an);
    updateH(bn);
    updateSum(an);
    updateSum(bn);
    return bn;
}

int LR(int an) {
    tr[an].l = RR(tr[an].l);
    return LL(an);
}

int RL(int an) {
    tr[an].r = LL(tr[an].r);
    return RR(an);
}

void insert(int& now, int key) {
    if (now == -1) {
        now = ++tp;
        tr[now].init(key);
    }
    else if (key <= tr[now].key) {
        insert(tr[now].l, key);
        if (getPHYZ(now) == 2) {
            if (key <= tr[tr[now].l].key) now = LL(now);
            else now = LR(now);
        }
    }
    else {
        insert(tr[now].r, key);
        if (getPHYZ(now) == -2) {
            if (getPHYZ(tr[now].r) <= 0)
                now = RR(now);
            else now = RL(now);
        }
    }
    updateH(now);
    updateSum(now);
}

void del(int& now, int key) {
    if (now == -1) return;
    if (key < tr[now].key) del(tr[now].l, key);
    else if (key > tr[now].key) del(tr[now].r, key);
    else {
        if (tr[now].l == -1) now = tr[now].r;
        else if (tr[now].r == -1) now = tr[now].l;
        else {
            int nex = tr[now].l;
            while (tr[nex].r != -1)
                nex = tr[nex].r;
            tr[now].key = tr[nex].key;
            del(tr[now].l, tr[nex].key);
        }
    }
    if (now == -1) return;
    updateH(now);
    updateSum(now);
    if (getPHYZ(now) == 2) {
        if (getPHYZ(tr[now].l) >= 0) now = LL(now);
        else now = LR(now);
    }
    else if (getPHYZ(now) == -2) {
        if (getPHYZ(tr[now].r) <= 0) now = RR(now);
        else now = RL(now);
    }
}

void findAndDel(int& rt, int k, int pos) {
    if (rt == -1) {
        printf("-1\n");
        return;
    }
    if (k == pos) {
        printf("%d\n", tr[rt].key);
        del(root, tr[rt].key);
    }
    else if (k < pos) {
        if (tr[tr[rt].l].r == -1) pos--;
        else pos -= tr[tr[tr[rt].l].r].sum + 1;
        findAndDel(tr[rt].l, k, pos);
    }
    else {
        if (tr[tr[rt].r].l == -1) pos++;
        else pos += tr[tr[tr[rt].r].l].sum + 1;
        findAndDel(tr[rt].r, k, pos);
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int op, k;
        scanf("%d%d", &op, &k);
        if (op == 1) {
            insert(root, k);
        }
        else if (op == 2) {
            int pos = tr[root].l == -1 ? 1 : (tr[tr[root].l].sum + 1);
            findAndDel(root, k, pos);
        }
    }
    return 0;
}