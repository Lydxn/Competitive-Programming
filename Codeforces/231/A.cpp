#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, p, v, t;
	cin >> n;

	int count = 0;
	while (n--)
	{
		cin >> p >> v >> t;
		count += p + v + t >= 2;
	}

	cout << count << '\n';
	return 0;
}
