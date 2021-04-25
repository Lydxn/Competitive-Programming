#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		if (i) cout << " that ";
		cout << (i % 2 ? "I love" : "I hate");
		if (i == n - 1) cout << " it";
	}
	return 0;
}
