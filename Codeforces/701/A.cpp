#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[100];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = make_pair(num, i + 1);
    }
    
    sort(a, a + n);
    
    for (int i = 0; i < n / 2; i++) cout << a[i].second << ' ' << a[n - i - 1].second << '\n';
    return 0;
}
