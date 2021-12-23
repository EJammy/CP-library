#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e9+100;
#define FOR(i, s, n) for(int i = s; i < n; i++)
const int S = 3e6;

struct FlowEdge{
	int v;
	ll cap;
	ll flow = 0;
	int revId;
	FlowEdge(int v_, ll cap_, int revId_):
		v(v_), cap(cap_), revId(revId_){}
	ll remCap(){
		assert(cap - flow >= 0);
		return cap - flow;
	}
};

struct Dinic{
	int n;
	vector<vector<FlowEdge>> G;
	vector<int> lvl;
	vector<int> itr;
	Dinic(int n_): n(n_), G(n), lvl(n, -1){}
	void addEdge(int u, int v, ll c){
		G[u].emplace_back(v, c, G[v].size());
		G[v].emplace_back(u, 0, G[u].size()-1);
	}
	void bfs(){
		lvl.assign(n, -1);
		lvl[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for (auto it: G[u]){
				if (it.remCap() > 0 && lvl[it.v] == -1){
					lvl[it.v] = lvl[u] + 1;
					q.push(it.v);
				}
			}
		}
	}
	ll dfs(int u, ll curFlow){
		if (u == n-1){
			return curFlow;
		}
		while (itr[u] < G[u].size()){
			auto &it = G[u][itr[u]];
			if (lvl[it.v] == lvl[u] + 1 && it.remCap() > 0){
				ll fl = dfs(it.v, min(curFlow, it.remCap()));
				if (fl != 0){
					it.flow += fl;
					G[it.v][it.revId].flow -= fl;
					return fl;
				}
				// else dead end
			}
			itr[u]++;
			// else not valid path
		}
		return 0; // dead end
	}
	ll solve(){
		ll res = 0;
		int t = INF;
		while (t-- && t > 0){
			bfs();
			if (lvl[n-1] == -1){
				break;
			}
			ll x = 0;
			itr.assign(n, 0);
			do {
				res += x;
				x = dfs(0, INF);
			} while (x != 0 && t-- && t > 0);
			res += dfs(0, INF);
		}
		return res;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin>>n>>m;
	Dinic sol(n);
	for (int i = 0; i < m; i++){
		int u, v;
		ll w;
		cin>>u>>v>>w;
		u--; v--;
		sol.addEdge(u, v, w);
		sol.addEdge(v, u, w);
	}

	cout<<sol.solve()<<'\n';

	return 0;
}
