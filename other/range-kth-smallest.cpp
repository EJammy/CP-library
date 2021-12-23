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

struct Val {
	int sz;
	vector<int> v;
}

const int S = 2e5+10;
Val seg[S];
void build(vector<int> &v, int u, int l, int r) {
	if (r-l < 1) return;
	seg[u] = {r-l, vector<int>(v.begin()+l, v.begin()+r)};
	sort(seg[u].v.begin(), seg[u].v.end());
	int mid = (r+l)/2;
	build(v, 2*u, l, mid);
	build(v, 2*u+1, mid, r);
}
int query(int ql, int qr, int k, int u, int l, int r) {
	if (

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin>>t;
	while (t--) {
		int n;
		cin>>n;
		auto v = readVec<ll>(n);
	}

	return 0;
}
