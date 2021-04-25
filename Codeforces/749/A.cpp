#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n;

	k = n / 2;
	cout << k << '\n';

	for (int i = 1; i < k; i++)
	{
		cout << "2 ";
	}
	
	cout << n % 2 + 2;
	return 0;
}
