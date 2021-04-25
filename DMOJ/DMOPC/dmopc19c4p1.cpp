#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    string S;
    cin >> N;

    while (N--)
    {
        cin >> S;

        int cnt = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(') ++cnt;
            else if (S[i] == ')')
            {
                if (cnt == 0)
                {
                    cout << "NO\n";
                    goto next;
                }
                else --cnt;
            }
        }
        cout << (cnt == 0 ? "YES" : "NO") << '\n';
        next:;
    }
    return 0;
}
