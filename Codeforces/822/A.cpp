#include <bits/stdc++.h>

using namespace std;

const int fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;
    
    cout << fact[min(A, B)] << '\n';
    return 0;
}
