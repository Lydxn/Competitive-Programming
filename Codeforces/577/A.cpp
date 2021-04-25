#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n >> x;

	int cells = 0;
	for (int i = 1; i <= n; i++)
	{
		if (x % i == 0 && x / i <= n) ++cells;
	}

	cout << cells << '\n';
	return 0;
}
