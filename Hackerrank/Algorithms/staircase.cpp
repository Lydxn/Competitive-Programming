#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cout << string(n - i, ' ') << string(i, '#') << '\n';
	}
	return 0;
}
