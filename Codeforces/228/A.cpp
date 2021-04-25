#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;

	unordered_set<int> set;
	set.insert(s1), set.insert(s2), set.insert(s3), set.insert(s4);

	cout << 4 - set.size() << '\n';
	return 0;
}
