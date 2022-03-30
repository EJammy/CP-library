/*
 * Problem: Given n and m, return a list of coordinates with all the points on a grid of size
 * n*m such that for all i < n*m, v[i] and v[i+1] is not on the same row, column, or diagonal
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int n, m;
bool check(int x1, int y1, int x2, int y2) {
	return x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2);
}

bool check2(vi v1, vi v2, int r1, int r2) {
	for (int i = 0; i < m; i++) {
		if (!check(r1, v1[i], r2, v2[i])) return false;
	}
	return true;
}

mt19937 rng(0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	bool doSwap = 0;
	cin >> n >> m;
	if (n <= 3 && m <= 3) {
		cout << -1 << '\n';
		return 0;
	}

	if (n > m) {
		swap(n, m);
		doSwap = 1;
	}
	vector<vi> ord(n, vi(m));
	vi row(n); // order of row
	iota(row.begin(), row.end(), 0);
	int t = 10;
	bool f = 0;
	while (t-- && !f) {
		shuffle(row.begin(), row.end(), rng);
		for (auto &it: ord) iota(it.begin(), it.end(), 0);
		for (int i = 1; i < n-1; i++) {
			int maxRep = 2000;
			while (!check2(ord[i-1], ord[i], row[i-1], row[i]) && maxRep--) {
				shuffle(ord[i].begin(), ord[i].end(), rng);
			}
		}
		int maxRep = 5000;
		vi &v = ord[n-1];
		vi v0 = ord[0];
		v0.push_back(v0[0]);
		v0.erase(v0.begin());
		while (maxRep--) {
			shuffle(v.begin(), v.end(), rng);
			if (check2(ord[n-2], v, row[n-2], row[n-1]) && check2(v0, v, row[0], row[n-1])) {
				f = 1;
				break;
			}
		}
	}

	if (!f) {
		cout << -1 << '\n';
		return 0;
	}

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			int x = row[i];
			int y = ord[i][j];
			if (doSwap) swap(x, y);
			cout << x + 1 << ' ' << y + 1 << '\n';
		}
	}

	int x = row[0], y = ord[0][0];
	if (doSwap) swap(x, y);
	cout << x + 1 << ' ' << y + 1 << '\n';

	return 0;
}
