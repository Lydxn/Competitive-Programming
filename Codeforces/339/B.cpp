#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, curr = 1;
	cin >> n >> m;

	long long time = 0;
	while (m--)
	{
		cin >> a;
		time += a - curr + (curr <= a ? 0 : n);
		curr = a;
	}

	cout << time << '\n';
	return 0;
}
