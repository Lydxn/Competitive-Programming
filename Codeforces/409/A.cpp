#include <iostream>
#include <string>

#define move(c) c == '(' ? 1 : (c == '[' ? 2 : 3);

using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string team1, team2;
	cin >> team1 >> team2;

	int score = 0, move1, move2;
	for (int i = 0; i < team1.size(); i += 2)
	{
		move1 = move(team1[i]);
		move2 = move(team2[i]);
		
		if (move1 != move2)
		{
			if ((move1 == 2 && move2 == 1) || (move1 == 3 && move2 == 2) || (move1 == 1 && move2 == 3)) ++score;
			else																						                                            --score;
		}
	}

	cout << (score > 0 ? "TEAM 1 WINS" :
			 score < 0 ? "TEAM 2 WINS" :
						 "TIE") << '\n';
	return 0;
}
