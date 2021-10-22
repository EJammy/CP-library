/*
alias cfast='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'
alias csafe='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void printVec(vector<T> v) {
    for (auto it: v) {
        cout<<it<<' ';
    }
    cout<<'\n';
}


vector<int> primes;
vector<bool> isp;
void sieve(int maxn)
{
    isp.assign(maxn, 1);
    isp[0] = isp[1] = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (isp[i])
        {
            primes.push_back(i);
            for (int j = i+i; j < maxn; j+=i)
            {
                isp[j] = 0;
            }
        }
    }
}

vector<ll> pfact(ll x)
{
    vector<ll> ret;
    for (auto p: primes)
    {
        if (x % p == 0) ret.push_back(p);
        while (x % p == 0)
        {
            x /= p;
        }
    }
    if (x != 1) ret.push_back(x);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve(30);
    printVec(primes);
    printVec(pfact(37));
    return 0;
}