#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	bool coloured = false;
	char pixel;

	for (int i = 0; i < n * m; i++)
	{
		cin >> pixel;
		if (pixel == 'C' || pixel == 'M' || pixel == 'Y') 
		{
			coloured = true;
			break;
		}
	}

	cout << (coloured ? "#Color" : "#Black&White") << '\n';
	return 0;
}
