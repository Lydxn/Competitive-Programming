#include <bits/stdc++.h>

using namespace std;

int a[1000000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long cost = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];

    for (int i = 1; i < N; i++) cost += max(a[i], a[i - 1]);

    cout << cost << '\n';
    return 0;
}
