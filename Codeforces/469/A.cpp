#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, p, a;
	cin >> n;

	unordered_set<int> set;
	for (int i = 0; i < 2; i++)
	{
		cin >> p;
		while (p--)
		{
			cin >> a;
			set.insert(a);
		}
	}

	cout << (set.size() == n ? "I become the guy." : "Oh, my keyboard!") << '\n';
	return 0;
}
