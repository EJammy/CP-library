/*
alias cfast='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'
alias csafe='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T>
void print(T val) {
    cout<<val<<' ';
}aaa

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
    vector<int> a;
    println("hello", "world", 1, 2, 3.1);

    return 0;
}