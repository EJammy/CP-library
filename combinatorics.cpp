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

#warning change these values
const ll MOD = 998244353;
const int S = 1e5+10;

ll fact[S];

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b % 2 == 1)
		{
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}
ll inv(ll x)
{
	return binpow(x, MOD-2);
}
ll C(ll n, ll r)
{
	ll ret = fact[n]*inv(fact[r]) % MOD;
	return ret * inv(fact[n-r]) % MOD;
}
void calcFact()
{
	fact[0] = 1;
	for (int i = 1; i < S; i++)
	{
		fact[i] = fact[i-1] * i % MOD;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	calcFact();
	println(C(5, 3));

	return 0;
}
