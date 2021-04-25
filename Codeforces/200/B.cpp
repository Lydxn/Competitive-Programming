#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n;

	double avg = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		avg += p;
	}

	cout << avg / n << '\n';
	return 0;
}
