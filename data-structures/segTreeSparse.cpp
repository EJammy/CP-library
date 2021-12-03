/*
https://tioj.ck.tp.edu.tw/problems/1169
*/
/*
alias cfast='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'
alias csafe='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void print(T val) {
	cout<<val;
}

template<typename T1, typename... T>
void print(T1 x, T... args) {
	cout<<x<<' ';
	print(args...);
}

template<typename... T>
void println(T... args) {
	print(args..., '\n');
}

template<typename T>
vector<T> readVec(int size) {
	vector<T> v(size);
	for (int i = 0; i < size; i++) {
		cin>>v[i];
	}
	return v;
}

template<typename T>
void printVec(vector<T> v) {
	for (auto it: v) {
		cout<<it<<' ';
	}
	cout<<'\n';
}

void pYesNo(bool x) {
	if (x) cout<<"Yes\n"; else cout<<"No\n";
}

struct Val
{
	int lv;
	int rv;
	int v;
	int sz;
	Val(int size = 0) { lv = rv = v = sz = size; }
};

Val join(Val l, Val r)
{
	Val ret(-1);
	if (l.v == l.sz) ret.lv = l.sz + r.lv;
	else ret.lv = l.lv;
	if (r.v == r.sz) ret.rv = r.sz + l.rv;
	else ret.rv = r.rv;
	ret.v = max({l.v, r.v, l.rv+r.lv});
	ret.sz = l.sz + r.sz;
	return ret;
}

struct SegT
{
	Val val;
	SegT *lc = NULL;
	SegT *rc = NULL;
	SegT(int size) : val(size) {}
};

const int S = (1<<24) + 10;
SegT *head[S] = {NULL};

void modify(SegT *u, int id, int l, int r, int x)
{
	assert(u);
	if (id >= r || id < l) return;
	if (l == id && r == l+1)
	{
		u->val.lv = u->val.rv = u->val.v = 1-x;
	}
	if (r-l <= 1) return;
	int mid = (l+r)/2;
	if (u->lc == NULL) u->lc = new SegT(mid-l);
	if (u->rc == NULL) u->rc = new SegT(r-mid);
	modify(u->lc, id, l, mid, x);
	modify(u->rc, id, mid, r, x);
	u->val = join(u->lc->val, u->rc->val);
}

Val query(SegT *u, int ql, int qr, int l, int r)
{
	// assert(r-l == u->val.sz);
	// cout<<u->val.v<<'\n';
	if (l >= qr || r <= ql) return Val(0);
	if (!u) return Val(min(r, qr) - max(l,ql));
	if (l >= ql && r <= qr) return u->val;

	Val lx, rx;
	int mid = (l+r)/2;
	// if (!u->lc) lx = Val(max(mid-ql, 0));
	lx = query(u->lc, ql, qr, l, mid);

	// if (!u->rc) rx = Val(max(qr-mid, 0));
	rx = query(u->rc, ql, qr, mid, r);

	// cout<<l<<' '<<r<<' '<<join(lx,rx).v<<'\n';

	return join(lx, rx);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c, q;
	cin>>n>>q>>c;
	auto v = readVec<int>(n);
	for (int i = 0; i < n; i++)
	{
		if (!head[v[i]])
			head[v[i]] = new SegT(n);
		modify(head[v[i]], i, 0, n, 1);
	}
	while (q--)
	{
		int qt; cin>>qt;
		if (qt == 0)
		{
			int id, x; cin>>id>>x;
			modify(head[v[id]], id, 0, n, 0);
			if (!head[x]) head[x] = new SegT(n);
			modify(head[x], id, 0, n, 1);
			v[id] = x;
		}
		else
		{
			int l, r, k;
			cin>>l>>r>>k;
			if (head[k] == NULL) cout<<(r-l)<<'\n';
			else
				cout<<query(head[k], l, r, 0, n).v<<'\n';
			// cout<<"====\n";
		}
	}
	return 0;
}
/*
5 2 4
0 0 0 1 0
1 1 5 1
1 0 5 1
*/
