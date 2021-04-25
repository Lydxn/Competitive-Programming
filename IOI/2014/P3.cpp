#include <bits/stdc++.h>

using namespace std;

int c[1500];

void initialize(int n) {}

int hasEdge(int u, int v) {
	if (u < v) swap(u, v);
	return ++c[u] == u;
}
