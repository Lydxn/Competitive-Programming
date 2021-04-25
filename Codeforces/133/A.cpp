#include <iostream>

using namespace std;

const string hq9 = "HQ9";

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string p;
	cin >> p;

	bool output = false;
	for (char c : p)
	{
		if (hq9.find(c) != string::npos) output = true;
	}

	cout << (output ? "YES" : "NO") << '\n';
	return 0;
}
