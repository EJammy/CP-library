/* https://cses.fi/problemset/task/1737/ */
#include<bits/stdc++.h>
 
using ll = long long;
using namespace std;
 
template<typename T>
vector<T> readVec(int n)
{
    vector<T> v(n);
    for (auto &it: v) cin>>it;
    return v;
}
 
template<typename T>
void printVec(vector<T> v)
{
    for (auto &it: v) cout<<it<<' ';
    cout<<'\n';
}
 
ll INF = 1e9+100;
struct SegT
{
    ll sum = 0;
    SegT * lc;
    SegT * rc;
    void pull()
    {
        sum = lc->sum + rc->sum;
    }
};
 
 
 
void build(SegT * u, int l, int r, vector<ll> &v)
{
    if (r-l < 1) return;
    if (r - l == 1)
    {
        u->sum = v[l];
        return;
    }
    int mid = (r+l)/2;
    u->lc = new SegT;
    u->rc = new SegT;
    build(u->lc, l, mid, v);
    build(u->rc, mid, r, v);
    u->pull();
}
 
ll query(SegT * u, int ql, int qr, int l, int r)
{
    if (r <= ql || l >= qr) return 0;
    if (l >= ql && r <= qr) return u->sum;
    int mid = (l+r)/2;
    return query(u->lc, ql, qr, l, mid) + query(u->rc, ql, qr, mid, r);
}
 
void update(SegT *u, SegT *old, int id, int x, int l, int r)
{
    if (id < l || id >= r) return;
    if (id == l && id+1==r)
    {
        u->sum = x;
        return;
    }
    int mid = (l+r)/2;
    if (id < mid)
    {
        u->rc = old->rc;
        u->lc = new SegT;
        update(u->lc, old->lc, id, x, l, mid);
    }
    else
    {
        u->lc = old->lc;
        u->rc = new SegT;
        update(u->rc, old->rc, id, x, mid, r);
    }
    u->pull();
}
 
const int S = 2e5+10;
SegT *head[S];
int segMx = 1;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    head[0] = new SegT;
    int n, q;
    cin>>n>>q;
    auto v = readVec<ll>(n);
    build(head[0], 0, n, v);
 
    vector<int> id;
    id.push_back(0);
 
    while (q--)
    {
        int qt;
        cin>>qt;
        if (qt == 1)
        {
            int k, a, x;
            cin>>k>>a>>x;
            k--; a--;
            head[segMx] = new SegT;
            update(head[segMx], head[id[k]], a, x, 0, n);
            id[k] = segMx;
            segMx++;
        }
        if (qt == 2)
        {
            int k, a, b;
            cin>>k>>a>>b; a--; k--;
            cout<<query(head[id[k]], a, b, 0, n)<<'\n';
        }
        if (qt == 3)
        {
            int k; cin>>k;
            k--;
            id.push_back(id[k]);
        }
    }
}
