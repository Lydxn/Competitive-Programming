#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii W[200000];

int find_subset(int l, int u, int w[], int n, int result[]) {
	for (int i = 0; i < n; i++) W[i] = {w[i], i};
	sort(W, W + n);

	ll sum = 0;
	for (int L = 0, R = 0; L < n; sum -= W[L++].first) {
		while (R < n && sum < l) sum += W[R++].first;
		if (l <= sum && sum <= u) {
			for (int i = L; i < R; i++) result[i - L] = W[i].second;
			return R - L;
		}
	}
	return 0;
}
