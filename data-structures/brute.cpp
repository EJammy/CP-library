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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, c, q;
	cin>>n>>q>>c;
	auto v = readVec<int>(n);
	while (q--)
	{
		int qt; cin>>qt;
		if (qt == 0)
		{
			int id, x; cin>>id>>x;
			v[id] = x;
		}
		else
		{
			// printVec(v);
			int l, r, k;
			cin>>l>>r>>k;
			int cur = 0;
			int ans = 0;
			for (int i = l; i < r; i++)
			{
				if (v[i] != k)
				{
					cur++;
					ans = max(ans, cur);
				}
				else
				{
					cur = 0;
				}
			}
			cout<<ans<<'\n';
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
