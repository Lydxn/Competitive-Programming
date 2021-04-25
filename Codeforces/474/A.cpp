#include <iostream>
#include <string>

using namespace std;

string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	char dir;
	string seq;
	cin >> dir >> seq;

	int dir_index = dir == 'L' ? 1 : -1;
	for (char c : seq)
	{
		cout << keyboard[keyboard.find(c) + dir_index];
	}
	return 0;
}
