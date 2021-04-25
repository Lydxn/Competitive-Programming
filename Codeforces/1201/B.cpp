#include <algorithm>
#include <iostream>

using namespace std;

int a[100000];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, sum = 0, max_ele;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i : a)
	{
		max_ele = max(max_ele, i);
		sum += i;
	}

	cout << (sum % 2 == 0 && sum >= 2 * max_ele ? "YES" : "NO") << '\n';
	return 0;
}
