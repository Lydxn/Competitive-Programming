#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int pos[200002], posl[100001], posr[100001], diff[200002], cnt[100001];
unordered_map<int, int> ind;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, R, Y, x, v, h;
	cin >> N >> L >> R >> Y;

	for (int i = 0; i < N; i++) {
		cin >> x >> v >> h;
		int l = x - Y * h / v + (Y * h % v == 0), r = x + Y * h / v - (Y * h % v == 0);
		pos[i << 1] = (posl[i] = max(l, L)), pos[i << 1 | 1] = (posr[i] = min(r, R) + 1);
	}
	pos[N << 1] = (posl[N] = L), pos[N << 1 | 1] = (posr[N] = R + 1), ++N;

	sort(pos, pos + (N << 1));
	for (int i = 0; i < N << 1; i++) ind[pos[i]] = i + 1;
	for (int i = 0; i < N; i++) ++diff[ind[posl[i]]], --diff[ind[posr[i]]];
	for (int i = 1; i < N << 1; i++) diff[i] += diff[i - 1], cnt[diff[i] - 1] += pos[i] - pos[i - 1];

	for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
	for (int i = 0; i < N; i++) cout << cnt[i] << '\n';
	return 0;
}
