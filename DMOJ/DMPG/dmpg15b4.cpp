#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, c, ans = 1;
    cin >> N;

    if (N == 1)
    {
        cin >> c;
        cout << c << '\n';
        return 0;
    }

    vector<int> pos, neg;

    for (int i = 0; i < N; i++)
    {
        cin >> c;
        if (c > 0) pos.push_back(c);
        if (c < 0) neg.push_back(c);
    }

    if (pos.empty() && neg.empty() || neg.size() == 1 && pos.size() == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < pos.size(); i++) ans *= pos[i];
    sort(neg.begin(), neg.end());
    for (int i = 0; i < neg.size() - int(neg.size()) % 2; i++) ans *= neg[i];

    cout << ans << '\n';
    return 0;
}
