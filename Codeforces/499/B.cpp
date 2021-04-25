#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	unordered_map<string, string> notes;
	string a, b, c;

	while (m--)
	{
		cin >> a >> b;
		notes[a] = a.size() > b.size() ? b : a;
	}

	while (n--)
	{
		cin >> c;
		cout << notes[c] << ' ';
	}
	return 0;
}
