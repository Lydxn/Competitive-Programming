#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string table_card, hand_card;
    cin >> table_card;
    
    for (int i = 0; i < 5; i++)
    {
        cin >> hand_card;
        if (table_card[0] == hand_card[0] || table_card[1] == hand_card[1])
        {
            cout << "YES\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
