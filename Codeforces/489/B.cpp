#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int a[100], b[100];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, pairs = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(b, b + m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (abs(a[i] - b[j]) <= 1)
			{
				++pairs;
				b[j] = INT_MAX;
				break;
			}
		}
	}

	cout << pairs << '\n';
	return 0;
}
