#include <algorithm>
#include <iostream>

using namespace std;

int b[200000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	long long n, max_cnt = 0, min_cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b, b + n);

	for (int i : b)
	{
		if (i == b[n - 1]) ++max_cnt;
		if (i == b[0]) ++min_cnt;
	}

	cout << b[n - 1] - b[0] << ' ' << (max_cnt == n ? n * (n - 1) / 2 : max_cnt * min_cnt) << '\n';
	return 0;
}
