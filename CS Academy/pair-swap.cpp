#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int A[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	if (K != 1) {
		deque<int> dq;
		for (int i = 1; i < K; i++) {
			while (!dq.empty() && A[i] <= A[dq.back()]) dq.pop_back();
			dq.push_back(i);
		}
		for (int i = 0; i < N; i++) {
			if (dq.front() == i) dq.pop_front();
			while (i + K < N && !dq.empty() && A[i + K] <= A[dq.back()]) dq.pop_back();
			dq.push_back(i + K);
			if (A[dq.front()] < A[i])
				{ swap(A[i], A[dq.front()]); break; }
		}
	}
	for (int i = 0; i < N; i++) cout << A[i] << " \n"[i == N - 1];
	return 0;
}
