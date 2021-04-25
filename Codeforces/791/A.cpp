#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int years;
	for (years = 0; a <= b; years++, a *= 3, b *= 2);

	cout << years << '\n';
	return 0;
}
