#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int u[200000], v[200000], cntp[1000001], cntm[1000001];
ll psap[1000001], psam[1000001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, P, M, a, b, mini = 0, MAXP = 0, MAXM = 0; ll minv = LLONG_MAX, curv;
	cin >> N >> P >> M;
	for (int i = 0; i < N; i++) cin >> u[i] >> v[i];
	for (int i = 0; i < P; i++) cin >> a, ++cntp[a], MAXP = max(MAXP, a);
	for (int i = 0; i < M; i++) cin >> b, ++cntm[b], MAXM = max(MAXM, b);

	for (int i = MAXP; i > 0; i--) psap[i] += psap[i + 1] + (cntp[i] += cntp[i + 1]);
	for (int i = MAXM; i > 0; i--) psam[i] += psam[i + 1] + (cntm[i] += cntm[i + 1]);

	for (int i = 0; i < N; i++) {
		curv = psap[u[i] + 1] + psam[v[i] + 1];
		if (curv < minv) minv = curv, mini = i;
	}

	cout << mini + 1 << '\n';
	return 0;
}
