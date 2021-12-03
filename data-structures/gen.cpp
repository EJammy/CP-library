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
void printVec(vector<T> v) {
	for (auto it: v) {
		cout<<it<<' ';
	}
	cout<<'\n';
}


// mt19937 rng(time(NULL));
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng((uint64_t) new char);
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	rng.seed(atoi(argv[1]));

	const int n = 2e5;
	const int q = 2e5;
	ll aMax = 1<<24;
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = rng()%aMax;
	println(n, q, 24);
	printVec(v);
	aMax = 10;

	for (int i = 0; i < q; i++)
	{
		int l = rng() % n;
		if (i < q-3 && rng() % 2 == 0)
		{
			println(0, l, rng() % aMax);
		}
		else
		{
			int r = rng()%(n-l) +1+l;
			println(1, l, r, rng() % aMax);
		}
	}

	return 0;
}
