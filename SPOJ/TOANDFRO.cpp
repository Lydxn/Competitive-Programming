#include <iostream>

using namespace std;

char res[200][200];

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	string message;

	int cols, rows;
	while (cin >> cols && cols)
	{
		cin >> message;
		rows = message.size() / cols;
		
		int k = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				res[i][i % 2 == 0 ? j : cols - j - 1] = message[k++];
			}
		}

		for (int i = 0; i < cols; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << res[j][i];
			}
		}
		cout << "\n";
	}
	return 0;
}
