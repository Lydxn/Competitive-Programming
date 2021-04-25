#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int c1, c2, c3, c4, c5, sum;
	cin >> c1 >> c2 >> c3 >> c4 >> c5;

	sum = c1 + c2 + c3 + c4 + c5;
	cout << (sum % 5 || sum == 0 ? -1 : sum / 5) << '\n';
	return 0;
}
