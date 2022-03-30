#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

bool check(int x1, int y1, int x2, int y2) {
	return x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2);
}
int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	if (n == 2 && m == 4 || n == 4 && m == 2) {
		int x;
		cin>>x;
		assert(x == -1);
		return 0;
	}

	int lx = -1, ly;
	set<pair<int,int>> s;
	for (int i = 0; i < n*m+1; i++) {
		int x, y;
		assert(cin >> x >> y);
		if (lx != -1) assert(check(lx, ly, x, y));
		assert(x >= 1 && x <= n && y >= 1 && y <= m);
		lx = x;
		ly = y;
		s.insert({x, y});
	}
	assert((int)s.size() == n*m);

	return 0;
}
