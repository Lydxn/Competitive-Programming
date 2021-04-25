#include <algorithm>
#include <iostream>

using namespace std;

int ar[10000000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, max_height = 0, count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		max_height = max(max_height, ar[i]);
	}

	for (int a : ar)
	{
		if (a == max_height) count++;
	}

	cout << count << '\n';
	return 0;
}
