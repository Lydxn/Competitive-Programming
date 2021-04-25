#include <bits/stdc++.h>

using namespace std;

string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string day;
    cin >> day;

    for (int i = 0; i < 7; i++)
    {
        if (day == days[i])
        {
            cout << days[(i + 1) % 7] << '\n';
            return 0;
        }
    }
    return 0;
}
