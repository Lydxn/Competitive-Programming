#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> nums;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, n, sum = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n > 0) nums.push_back(n);
	}

	sort(nums.begin(), nums.end(), greater<int>());
	for (int i = 0; i < min(int(nums.size()), K); i++) sum += nums[i];
	cout << sum << '\n';
	return 0;
}
