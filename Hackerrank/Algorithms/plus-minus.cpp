#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, arr;
	cin >> n;

	float plus = 0, minus = 0, zero = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr;
		if (arr > 0)	  plus++;
		else if (arr < 0) minus++;
		else			  zero++;
	}

	cout << plus / n << '\n' << 
			minus / n << '\n' <<
			zero / n << '\n';
	return 0;
}
