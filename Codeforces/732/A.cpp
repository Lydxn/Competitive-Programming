#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int k, r, cost;
	cin >> k >> r;

	for (int i = k; ; i += k)
	{
		if (i % 10 == 0 || i % 10 == r)
		{
			cout << i / k << '\n';
			return 0;
		}
	}
}
