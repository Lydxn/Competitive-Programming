#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, i, sum = 0, curr = 0;
	cin >> n;

	for (i = 1; n >= sum; i++)
	{
		curr += i;
		sum += curr;
	}

	cout << i - 2 << '\n';
	return 0;
}
