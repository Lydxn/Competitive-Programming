#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	unordered_map<string, int> poly = { 
		{"Tetrahedron", 4}, 
		{"Cube", 6},
		{"Octahedron", 8}, 
		{"Dodecahedron", 12},
		{"Icosahedron", 20} };

	int faces = 0;
	while (n--)
	{
		cin >> s;
		faces += poly[s];
	}

	cout << faces << '\n';
	return 0;
}
