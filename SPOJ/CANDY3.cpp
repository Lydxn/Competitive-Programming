#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N;
	cin >> T;

	string blank;
	long long candy;
	for (int i = 0; i < T; i++)
	{
		getline(cin, blank);

		cin >> N;
		long long rem = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> candy;
			rem = (rem + candy) % N;
		}
		cout << (rem ? "NO" : "YES") << "\n";
	}
	return 0;
}
