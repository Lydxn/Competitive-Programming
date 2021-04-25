#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string word;
	cin >> word;

	word[0] = toupper(word[0]);
	cout << word << '\n';
	return 0;
}
