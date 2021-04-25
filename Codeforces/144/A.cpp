#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, min_a = INT_MAX, max_a = 0, min_i = INT_MAX, max_i = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a <= min_a) min_a = a, min_i = i;
		if (a > max_a) max_a = a, max_i = i;
	}

	cout << (max_i - 1) + (n - min_i) - (min_i < max_i) << '\n';
	return 0;
}
