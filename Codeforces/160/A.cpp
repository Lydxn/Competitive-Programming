#include <algorithm>
#include <iostream>

using namespace std;

int a[100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + n);
	sum >>= 1;

	int coins = 0;
	for (int i = n - 1; sum >= 0; i--, coins++) sum -= a[i];

	cout << coins << '\n';
	return 0;
}
