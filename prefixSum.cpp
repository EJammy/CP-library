#include <bits/stdc++.h>
using namespace std;

vector<int> genPsum(vector<int> &v) {
	auto psum = v;
	for (int i = 1; i < v.size(); i++)
	{
		psum[i] += psum[i-1];
	}
	psum.insert(psum.begin(), 0);
}
