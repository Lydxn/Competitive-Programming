#include <bits/stdc++.h>

using namespace std;

template <typename It>
std::vector<typename std::iterator_traits<It>::value_type> LIS(It st, It en) {
	typedef typename std::iterator_traits<It>::value_type T;
	int N = en - st, len = 0, lo, hi, mid; T *dp = new T[N], *nxt = new T[N];
	for (int i = 0; i < N; i++) {
		lo = 0, hi = len;
		while (lo < hi) {
		    mid = (lo + hi) / 2;
		    if (*(st + dp[mid]) < *(st + i)) lo = mid + 1;
		    else hi = mid;
		}
		if (len == hi) ++len;
		dp[hi] = i, nxt[i] = hi ? dp[hi - 1] : -1;
	}
	vector<T> lis(len); for (int i = dp[len - 1]; i != -1; i = nxt[i]) lis[--len] = *(st + i);
	return lis;
}

int arr[1000000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << LIS(arr, arr + N).size() << '\n';
    return 0;
}
