#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii a[1000001];

#define chk_min(ii, jj) { \
	int curval = abs(a[ii].first + a[jj].first), curi = a[ii].second, curj = a[jj].second; \
	if (curi > curj) swap(curi, curj); \
	if (curval < minval || (curval == minval && curi < mini) || (curval == minval && curi == mini && curj < minj)) \
		minval = curval, mini = curi, minj = curj; \
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, minval = INT_MAX, mini = INT_MAX, minj = INT_MAX;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + N + 1);

	for (int i = 1; i < N; i++) chk_min(i, i + 1);
	N = unique(a + 1, a + N + 1, [] (pii& a, pii& b) { return a.first == b.first; }) - a - 1;
	for (int i = 1, j = N; i <= N; i++) {
		while (i < j && -a[i].first < a[j].first) --j;
		if (j > i && j <= N) chk_min(i, j);
		if (j >= i && j < N) chk_min(i, j + 1);
	}

	cout << minval << '\n' << mini << ' ' << minj << '\n';
	return 0;
}
