/*
https://judge.yosupo.jp/problem/range_affine_range_sum
*/

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

const ll MOD = 998244353;
struct SegT
{
    ll val = 0;
    ll multTag = 1;
    ll addTag = 0;
    void setTag(int a, int b)
    {
        multTag = multTag * a % MOD;
        addTag = addTag * a % MOD + b;
        addTag %= MOD;
    }
    ll get()
    {
        return val*multTag + addTag;
    }
};

const int S = 7e5;
SegT seg[4*S];

void push(int v)
{
    seg[v*2].setTag(seg[v].multTag, seg[v].addTag);
    seg[v*2+1].setTag(seg[v].multTag, seg[v].addTag);
    seg[v].multTag = 1;
    seg[v].addTag = 0;
}
void pull(int v)
{
    seg[v].val = seg[v*2].get() + seg[v*2+1].get();
    seg[v].val %= MOD;
}

ll calc(int v, int ql, int qr, int l, int r) {
    if (l >= r) 
        return 0;
    if (l >= ql && r <= qr) {
        return seg[v].get();
    }
    if (r <= ql || l >= qr)
    {
        return 0;
    }
    push(v);
    int mid = (l + r) / 2;
    ll ret = calc(v*2, ql, qr, l, mid) + calc(v*2+1, ql, qr, mid, r);
    pull(v);
    return ret;
}

void update(int v, int ql, int qr, int l, int r, ll a, ll b)
{
    if (l >= r) 
        return;
    if (l >= ql && r <= qr)
    {
        seg[v].setTag(a, b);
        return;
    }
    if (r <= ql || l >= qr)
    {
        return;
    }
    push(v);
    int mid = (l + r) / 2;
    update(v*2, ql, qr, l, mid, a, b);
    update(v*2+1, ql, qr, mid, r, a, b);
    pull(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(12);


    int n, qc;
    cin>>n>>qc;
    for (int i = 0; i < n; i++)
    {
        int x; cin>>x;
        update(1, i, i+1, 0, n, 1, x);
    }
    while (qc--)
    {
        int q; cin>>q;
        int l, r;
        cin>>l>>r;
        if (q == 0)
        {
            int a, b; cin>>a>>b;
            update(1, l, r, 0, n, a, b);
        }
        else
        {
            println(calc(1, l, r, 0, n));
        }
    }
    return 0;
}