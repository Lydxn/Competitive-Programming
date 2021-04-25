#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int S[200001], dist[200001], seg[800001], V[200001];
vector<int> adj[200001];
queue<int> q;

void build(int s, int e, int pos) {
	if (s == e) seg[pos] = V[s];
	else {
		int mid = (s + e) >> 1;
		build(s, mid, pos << 1), build(mid + 1, e, pos << 1 | 1);
		seg[pos] = min(seg[pos << 1], seg[pos << 1 | 1]);
	}
}

void update(int i, int v, int s, int e, int pos) {
	if (s == e) seg[pos] += v;
	else {
		int mid = (s + e) >> 1;
		if (i <= mid) update(i, v, s, mid, pos << 1);
		else update(i, v, mid + 1, e, pos << 1 | 1);
		seg[pos] = min(seg[pos << 1], seg[pos << 1 | 1]);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, W, D, A, B;
	cin >> N >> W >> D;
	while (W--) {
		cin >> A >> B;
		adj[B].push_back(A);
	}

	memset(dist, 0x3f, sizeof(dist));
	q.push(N); dist[N] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i : adj[cur])
			if (dist[i] == 0x3f3f3f3f)
				dist[i] = dist[cur] + 1, q.push(i);
	}
	
	for (int i = 1; i <= N; i++) cin >> S[i], V[S[i]] = i - 1 + dist[S[i]];
	build(1, N, 1);
	
	for (int i = 0; i < D; i++) {
		cin >> A >> B;
		V[S[A]] += B - A, V[S[B]] += A - B;
		update(S[A], B - A, 1, N, 1), update(S[B], A - B, 1, N, 1);
		swap(S[A], S[B]);
		cout << seg[1] << '\n';
	}
	return 0;
}