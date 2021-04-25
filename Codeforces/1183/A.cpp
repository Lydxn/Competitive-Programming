#include <bits/stdc++.h>

using namespace std;

bool interesting(int a)
{
    int sum = 0;
    while (a)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum % 4 == 0;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    cin >> a;
    
    while (!interesting(a)) a++;
    cout << a << '\n';
    return 0;
}
