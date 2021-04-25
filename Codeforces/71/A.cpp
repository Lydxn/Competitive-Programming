#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, size;
	cin >> n;

	string word;
	while (n--)
	{
		cin >> word;
		size = word.size();
		cout << (size > 10 ? word[0] + to_string(size - 2) + word[size - 1] : word) << '\n';
	}
	return 0;
}
