#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

__gnu_pbds::priority_queue<int, less<int>, __gnu_pbds::pairing_heap_tag> pq[100001];
int B[100001], L[100001], C[100001];
ll W[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M; ll ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> B[i] >> C[i] >> L[i];
		W[i] += C[i], pq[i].push(C[i]);
	}

	for (int i = N; i >= 1; i--) {
		ans = max(ans, L[i] * (ll) pq[i].size());
		W[B[i]] += W[i], pq[B[i]].join(pq[i]);
		while (W[B[i]] > M) W[B[i]] -= pq[B[i]].top(), pq[B[i]].pop();
	}
	cout << ans << '\n';
	return 0;
}
