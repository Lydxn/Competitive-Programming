#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		if (x != y && x - y != 2)
		{
			cout << "No Number\n";
		}
		else
		{
			cout << x + y - (x & 1 || y & 1) << "\n";
		}
	}
	return 0;
}
