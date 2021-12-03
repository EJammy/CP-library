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
	int lc = -1;
	int rc = -1;
	SegT(int size = 0) : val(size) {}
};

const int S = 1<<24;
int head[S];
const int segS = 2e7;
int segMax = 0;
SegT nd[segS];

int nxtNd(int size)
{
	nd[segMax] = SegT(size);
	return segMax++;
}

void modify(int u, int id, int l, int r, int x)
{
	if (id >= r || id < l) return;
	if (l == id && r == l+1)
	{
		nd[u].val = Val(1);
		nd[u].val.lv = nd[u].val.rv = nd[u].val.v = 1-x;
	}
	if (r-l <= 1) return;
	int mid = (l+r)/2;
	if (nd[u].lc == -1) nd[u].lc = nxtNd(mid - l);
	modify(nd[u].lc, id, l, mid, x);
	if (nd[u].rc == -1) nd[u].rc = nxtNd(r-mid);
	modify(nd[u].rc, id, mid, r, x);

	nd[u].val = join(nd[nd[u].lc].val, nd[nd[u].rc].val);
}

Val query(int u, int ql, int qr, int l, int r)
{
	// cout<<ql<<' '<<qr<<' '<<l<<' '<<r<<'\n';
	if (r <= ql || l >= qr) return Val(0);
	if (u == -1) return Val(min(qr, r) - max(ql, l));
	if (l >= ql && r <= qr) return nd[u].val;

	int mid = (l+r)/2;
	return join(query(nd[u].lc, ql, qr, l, mid), query(nd[u].rc, ql, qr, mid, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(head, head + S, -1);

	// cout<<segMax++<<endl;
	// cout<<segMax<<endl;
	int n, c, q;
	cin>>n>>q>>c;
	auto v = readVec<int>(n);
	for (int i = 0; i < n; i++)
	{
		if (head[v[i]] == -1)
			head[v[i]] = nxtNd(n);
		modify(head[v[i]], i, 0, n, 1);
	}
	while (q--)
	{
		int qt; cin>>qt;
		if (qt == 0)
		{
			int id, x; cin>>id>>x;
			modify(head[v[id]], id, 0, n, 0);
			if (head[x] == -1) head[x] = nxtNd(n);
			modify(head[x], id, 0, n, 1);
			v[id] = x;
		}
		else
		{
			int l, r, k;
			cin>>l>>r>>k;
			if (head[k] == -1) cout<<(r-l)<<'\n';
			else
				cout<<query(head[k], l, r, 0, n).v<<'\n';
			// cout<<"====\n";
		}
	}

	return 0;
}
