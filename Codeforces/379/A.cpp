#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	cout << (a * b - 1) / (b - 1) << '\n';
	return 0;
}
