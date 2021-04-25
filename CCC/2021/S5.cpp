#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[150001], X[150000], Y[150000], Z[150000], seg[600001];

int gcd(int x, int y) { return x == -1 ? y : y == -1 ? x : __gcd(x, y); }
int lcm(int x, int y) { return x * y / __gcd(x, y); }

void update(int x, int y, int z, int ss, int se, int idx) {
	if (x > se || y < ss) return;
	if (ss >= x && se <= y) { seg[idx] = lcm(seg[idx], z); return; }
	int mid = (ss + se) >> 1;
	update(x, y, z, ss, mid, idx << 1), update(x, y, z, mid + 1, se, idx << 1 | 1);
}

int query(int x, int ss, int se, int idx) {
	if (ss == se) return seg[idx];
	int mid = (ss + se) >> 1;
	if (x <= mid) return lcm(seg[idx], query(x, ss, mid, idx << 1));
	else return lcm(seg[idx], query(x, mid + 1, se, idx << 1 | 1));
}

int query2(int x, int y, int ss, int se, int idx) {
	if (x > se || y < ss) return -1;
	if (ss >= x && se <= y) return seg[idx];
	int mid = (ss + se) >> 1;
	return gcd(query2(x, y, ss, mid, idx << 1), query2(x, y, mid + 1, se, idx << 1 | 1));
}

void build(int ss, int se, int idx) {
	if (ss == se) seg[idx] = A[ss];
	else {
		int mid = (ss + se) >> 1;
		build(ss, mid, idx << 1), build(mid + 1, se, idx << 1 | 1);
		seg[idx] = gcd(seg[idx << 1], seg[idx << 1 | 1]);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N * 4; i++) seg[i] = 1;
	for (int i = 0; i < M; i++) {
		cin >> X[i] >> Y[i] >> Z[i];
		update(X[i], Y[i], Z[i], 1, N, 1);
	}

	for (int i = 1; i <= N; i++) A[i] = query(i, 1, N, 1);
	build(1, N, 1);
	
	for (int i = 0; i < M; i++)
		if (query2(X[i], Y[i], 1, N, 1) != Z[i]) { cout << "Impossible\n"; return 0; }
	for (int i = 1; i <= N; i++) cout << A[i] << ' ';
	cout << '\n';
	return 0;
}