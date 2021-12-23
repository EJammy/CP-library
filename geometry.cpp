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

struct PT{
	ll x;
	ll y;
	PT operator+(PT o) { return PT{x+o.x, y+o.y}; }
	PT operator-(PT o) { return PT{x-o.x, y-o.y}; }
};

ll cross(PT a, PT b) {
	return a.x*b.y-b.x*a.y;
}
PT readPT() {
	ll x, y;
	cin>>x>>y;
	return PT{x,y};
}

int lineIntersect(PT a1, PT a2, PT b1, PT b2) { // line segment intersection
	ll c1 = cross(a2-a1, b1-a1);
	ll c2 = cross(a2-a1, b2-a1);
	if (c1 == 0 && c2 == 0) return 0;
	if (c1 > c2) swap(c1, c2);
	if (c1 <= 0 && c2 >= 0) return 1;
	return -1;
}

ll dot(PT a, PT b) {
	return a.x*b.x + a.y*b.y;
}

bool inBetween(PT a1, PT a2, PT b) { // when three points share line
	return dot(a2-b, a1-b) <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin>>t;
	while (t--) {
		PT a1 = readPT();
		PT a2 = readPT();
		PT b1 = readPT();
		PT b2 = readPT();
		int i1 = lineIntersect(a1, a2, b1, b2);
		int i2 = lineIntersect(b1, b2, a1, a2);
		bool ans = false;
		if (i1 == 0) {
			assert(i2 == 0);
			if (inBetween(a1, a2, b1) || inBetween(a1, a2, b2) || inBetween(b1, b2, a1)) {
				ans = 1;
			}
		}else {
			if (i1 == 1 && i2 == 1) ans = 1;
		}
		if (ans) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
