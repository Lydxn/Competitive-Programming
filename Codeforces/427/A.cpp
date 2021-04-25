#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, num, sum = 0, count = 0;
	cin >> n;

	while (n--)
	{
		cin >> num;

		sum += num;
		if (sum < 0)
		{
			sum = 0;
			count++;
		}
	}

	cout << count << '\n';
	return 0;
}
