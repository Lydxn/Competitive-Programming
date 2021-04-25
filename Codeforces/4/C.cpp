#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string line;
	unordered_map<string, int> users;

	while (n--)
	{
		cin >> line;
		if (users.find(line) == users.end())
		{
			cout << "OK\n";
			users[line] = 1;
		}
		else cout << line << users[line]++ << '\n';
	}
	return 0;
}
