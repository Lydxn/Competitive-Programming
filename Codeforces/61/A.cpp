#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.size(); i++)
	{
		cout << ((a[i] - '0') ^ (b[i] - '0'));
	}
	return 0;
}
