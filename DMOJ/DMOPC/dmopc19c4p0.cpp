#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == B[i]) ++cnt;
    }

    cout << (cnt == int(A.size()) - 1 && A != B ? "LARRY IS SAVED!" : "LARRY IS DEAD!") << '\n';
    return 0;
}
