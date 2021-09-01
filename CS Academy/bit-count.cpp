#include <bits/stdc++.h>
using namespace std;

int bitcount(int x) {
	return __builtin_popcount(x);
}
int main() {
    int x;
    cin >> x;
    cout << bitcount(x) << "\n";
    return 0;
}
