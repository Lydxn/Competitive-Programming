#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int num;
	while (cin >> num && num != 42)
	{
		cout << num << "\n";
	}
	return 0;
}
