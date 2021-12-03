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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++)
	{
		println(rng() % 100);
	}

	vector<int> v(10);
	iota(v.begin(), v.end(), 0);
	shuffle(v.begin(), v.end(), rng);
	printVec(v);

	return 0;
}
