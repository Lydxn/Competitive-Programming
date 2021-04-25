#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, L, arr[60];
	cin >> N;
	while (N--) {
		cin >> L;
		for (int i = 0; i < L; i++) cin >> arr[i];

		int cnt = 0;
		for (int i = 0; i < L; i++)
			for (int j = i + 1; j < L; j++)
				cnt += arr[i] > arr[j];
		cout << cnt << '\n';
	}
	return 0;
}
