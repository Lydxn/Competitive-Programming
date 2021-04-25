#include <algorithm>
#include <iostream>

using namespace std;

int a[100000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, neg = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] >= 0)
		{
			a[i] = ~a[i];
			++neg;
		}
		else --neg;
	}

	int min_a = 10000000, pos;
	if (neg % 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (min_a > a[i])
			{
				min_a = a[i];
				pos = i;
			}
		}
		a[pos] = ~a[pos];
	}

	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}
