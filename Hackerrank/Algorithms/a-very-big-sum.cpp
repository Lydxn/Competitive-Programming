#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, ar;
	long long sum = 0;
	cin >> n;

	while (n--)
	{
		cin >> ar;
		sum += ar;
	}

	cout << sum << '\n';
	return 0;
}
