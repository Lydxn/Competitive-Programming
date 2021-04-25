#include <algorithm>
#include <iostream>

using namespace std;

int a[12];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k, sum = 0, months = 0;
	cin >> k;

	for (int i = 0; i < 12; i++) cin >> a[i];
	sort(a, a + 12);

	if (k)
		for (int i = 11; i >= 0; i--)
		{
			if (sum < k)
			{
				sum += a[i];
				++months;
			}
		}

	cout << (sum < k ? -1 : months) << '\n';
	return 0;
}
