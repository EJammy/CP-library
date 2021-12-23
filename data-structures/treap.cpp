/*
alias cfast='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'
alias csafe='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

struct Node {
	int val;
	int pri;
	Node* lc = NULL;
	Node* rc = NULL;
	Node(int x): val(x), pri(rand()%100) {}
	int sz = 1;
	void pull() {
		sz = 1;
		if (lc) sz += lc->sz;
		if (rc) sz += rc->sz;
	}
	int lsize() { return lc?lc->sz:0; }
};

using Ptr = Node*;

Ptr merge(Ptr l, Ptr r) {
	if (!l) return r;
	if (!r) return l;
	if (l->pri > r->pri) {
		l->rc = merge(l->rc, r);
		l->pull();
		return l;
	}else {
		r->lc = merge(l, r->lc);
		r->pull();
		return r;
	}
}

pair<Ptr, Ptr> split(Ptr u, int x) {
	if (!u) return {NULL, NULL};
	if (x < u->val) {
		Ptr l;
		tie(l, u->lc) = split(u->lc, x);
		u->pull();
		return {l, u};
	}else {
		Ptr r;
		tie(u->rc, r) = split(u->rc, x);
		u->pull();
		return {u, r};
	}
}

pair<Ptr, Ptr> splitSize(Ptr u, int x) {
	if (!u) return {NULL, NULL};
	if (x <= u->lsize()) {
		Ptr l;
		tie(l, u->lc) = splitSize(u->lc, x);
		u->pull();
		return {l, u};
	}else {
		Ptr r;
		tie(u->rc, r) = splitSize(u->rc, x - u->lsize() - 1);
		u->pull();
		return {u, r};
	}
}

void printTree(Ptr u, int d = 0) {
	if (!u) return;
	cout << u->val << "-" << u->sz <<'\n';
	if (u->lc) {
		for (int i = 0; i < d; i++) cout<<" ";
		cout<<"L: "; printTree(u->lc, d+1);
	}
	if (u->rc) {
		for (int i = 0; i < d; i++) cout<<" ";
		cout<<"R: "; printTree(u->rc, d+1);
	}
	if (d == 0) cout<<'\n';
}

void insert(Ptr &root, int x) {
	if (root == NULL) {
		root = new Node(x);
		return;
	}
	auto [l, r] = split(root, x);
	l = merge(l, new Node(x));
	root = merge(l, r);
}

int remove(Ptr &root, int x) {
	auto [l, r] = splitSize(root, x-1);
	Ptr u = NULL;
	tie(u, r) = splitSize(r, 1);
	int ret = -1;
	if (u) ret = u->val;
	root = merge(l, u);
	root = merge(root, r);
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Ptr root = NULL;
	string s;
	int x = 1;
	while (s != "END") {
		cin>>s;
		if (s == "GET") {
			int ret = remove(root, x);
			if (root && root->sz >= x) {
				cout<<ret<<'\n';
				x++;
			}
		}else if (s == "PUSH") {
			int y; cin>>y;
			insert(root, y);
//			printTree(root);
		}else if (s == "EXIT") {
			x = 1;
			root = NULL;
		}
	}

	return 0;
}
