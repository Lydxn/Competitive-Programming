#include <bits/stdc++.h>

using namespace std;

bool is_perfect(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum == 10;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    
    for (int i = 1, count = 0; ; i++)
    {
        if (is_perfect(i)) ++count;
        if (count == k)
        {
            cout << i << '\n';
            return 0;
        }
    }
}
