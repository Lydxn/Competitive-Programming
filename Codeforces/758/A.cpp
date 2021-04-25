#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, sum = 0, max_a = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
		max_a = max(max_a, a);
	}

	cout << n * max_a - sum << '\n';
	return 0;
}
