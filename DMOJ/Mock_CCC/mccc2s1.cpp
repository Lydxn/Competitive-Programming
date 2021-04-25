#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, a[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a + N);
    for (int i = 0; i < N; i++) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}
