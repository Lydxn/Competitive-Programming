#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int arr[5], max_val = 0, min_val = INT_MAX;
	long long sum = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		min_val = min(min_val, arr[i]);
		max_val = max(max_val, arr[i]);
	}

	cout << sum - max_val << ' ' <<
			sum - min_val << '\n';
	return 0;
}
