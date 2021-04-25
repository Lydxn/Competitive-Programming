#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int A, B, C, X, Y, Z, AX, BY, CZ;
	cin >> A >> B >> C >> X >> Y >> Z;

	AX = abs(A - X), BY = abs(B - Y), CZ = abs(C - Z);

	cout << max(AX, max(BY, CZ)) << '\n';
	cout << (int) sqrt(AX * AX + BY * BY + CZ * CZ) << '\n';
	cout << AX + BY + CZ << '\n';
	return 0;
}
