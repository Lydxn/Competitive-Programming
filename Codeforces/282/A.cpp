#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, X = 0;
	cin >> n;

	string statement;
	while (n--)
	{
		cin >> statement;
		if (statement == "X++" || statement == "++X") X++;
		else										  X--;
	}

	cout << X;
	return 0;
}
