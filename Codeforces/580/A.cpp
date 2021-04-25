#include <algorithm>
#include <iostream>

using namespace std;

int a[100000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	int maxlen = 0, len = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= a[i + 1]) len++;
		else
		{
			maxlen = max(maxlen, len);
			len = 1;
		}
	}

	cout << maxlen << '\n';
	return 0;
}
