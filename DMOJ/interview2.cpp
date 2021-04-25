#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll A[5000];
unordered_set<ll> aset;
unordered_set<ll> uniq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i], aset.insert(A[i]);

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (aset.count(A[i] + A[j])) {
				uniq.insert(min(A[i], A[j]) << 20LL | max(A[i], A[j]));
			}
		}
	}

	int ans = uniq.size();
	cout << (ans == 0 ? -1 : ans) << '\n';
	return 0;
}
