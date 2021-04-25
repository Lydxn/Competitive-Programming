#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct node {
	int Va, Vb; string ans;
	node(int Va, int Vb, string ans) : Va(Va), Vb(Vb), ans(ans) {}
};

queue<node> q;
bool vis[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int Va, Vb, M;
	cin >> Va >> Vb >> M;

	q.emplace(0, 0, "");
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.Va == M || cur.Vb == M) {
			cout << cur.ans << '\n';
			return 0;
		}

		if (vis[cur.Va][cur.Vb]) continue;
		vis[cur.Va][cur.Vb] = true;

		q.emplace(Va, cur.Vb, cur.ans + "fill A\n");
		q.emplace(cur.Va, Vb, cur.ans + "fill B\n");
		q.emplace(max(0, cur.Va - Vb + cur.Vb), min(Vb, cur.Va + cur.Vb), cur.ans + "pour A B\n");
		q.emplace(min(Va, cur.Vb + cur.Va), max(0, cur.Vb - Va + cur.Va), cur.ans + "pour B A\n");
		q.emplace(0, cur.Vb, cur.ans + "chug A\n");
		q.emplace(cur.Va, 0, cur.ans + "chug B\n");
	}

	cout << "Not possible\n";
	return 0;
}
