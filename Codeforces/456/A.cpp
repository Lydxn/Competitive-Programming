#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;

	bool alex = false;
	while (n--)
	{
		cin >> a >> b;
		if (a != b)
		{
			alex = true;
			break;
		}
	}

	cout << (alex ? "Happy Alex" : "Poor Alex");
	return 0;
}
