#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> primes = {{2, 3}, {3, 5}, {5, 7}, {7, 11}, {11, 13}, {13, 17}, {17, 19}, {19, 23}, {23, 29}, {29, 31}, {31, 37}, {37, 41}, {41, 43}, {43, 47}};

bool adj_primes(int n, int m)
{
    for (const auto& p : primes)
    {
        if (p.first == n && p.second == m) return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    cout << (adj_primes(n, m) ? "YES" : "NO") << '\n';
    return 0;
}
