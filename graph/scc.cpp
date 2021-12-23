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

const int S = 1e5+5;
vector<int> g[S];
vector<int> rev[S];
bool vis[S];

void dfs1(int u, vector<int> &res) {
	if (!vis[u]) {
		vis[u] = 1;
		for (auto it: rev[u]) dfs1(it, res);
		res.push_back(u);
	}
}

int scc[S];
int sccx[S];
int cnt = 0;
void dfs2(int u, int x) {
	if (!vis[u]) {
		vis[u] = 1;
		scc[u] = x;
		for (auto it: g[u]) dfs2(it, x);
	}
}

vector<int> g2[S];
int outdeg[S] = {0};
int dfs(int u) {
	if (vis[u]) return -1;
	vis[u] = 1;
	if (outdeg[u] == 0) return u;
	for (auto it: g2[u]) {
		int x = dfs(it);
		if (x != -1) return x;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin>>n>>m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b; a--; b--;
		g[a].push_back(b);
		rev[b].push_back(a);
	}


	vector<vector<int>> ord;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			vector<int> res;
			dfs1(i, res);
			reverse(res.begin(), res.end());
			ord.push_back(res);
		}
	}
	reverse(ord.begin(), ord.end());

	fill(vis, vis+n, 0);
	for (auto itt: ord) {
		for (auto u: itt) {
			// cout<<u+1<<' ';
			if (!vis[u]) {
				dfs2(u, cnt);
				sccx[cnt] = u;
				cnt++;
			}
		}
		// cout<<"==\n";
	}

	vector<int> indeg(cnt, 0);
	for (int i = 0; i < n; i++) {
		for (auto it: g[i]) {
			if (scc[i] != scc[it]) {
				indeg[scc[it]]++;
				outdeg[scc[i]]++;
				g2[scc[i]].push_back(scc[it]);
			}
		}
	}
	
	for (int i = 0; i < cnt; i++) {
		cout<<scc[i]<<' ';
	}

	int i0 = 0;
	int o0 = 0;
	for (int i = 0; i < cnt; i++) {
		if (indeg[i] == 0) i0++;
		if (outdeg[i] == 0) o0++;
	}
	cout<<'\n';
	cout<<i0<<' '<<o0<<'\n';


	return 0;
}
