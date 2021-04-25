#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	
	int count = 0;
	for (int i = 0; i < s.size() - 1; i++)
	{
		count += s[i] == s[i + 1];
	}

	cout << count << '\n';
	return 0;
}
