#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	string seq;
	while (t--)
	{
		cin >> seq;
		for (int i = 0; i < seq.size() / 2; i += 2)
		{
			cout << seq[i];
		}
		cout << "\n";
	}
}
