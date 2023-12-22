#include<iostream>
#include<vector>

using namespace std;

void DisplayBoard(const vector<vector<char>>& board)
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			cout << board[a][b];
			if (b < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;

		if (a < 2)
		{
			cout << "---------" << endl;
		}
	}
	cout << endl;
}

bool Win(const vector<vector<char>>& board, char player)
{
	for (int c = 0; c < 3; c++)
	{
		if (board[c][0] == player && board[c][1] == player && board[c][2] == player || board[0][c] == player && board[1][c] == player && board[2][c])
		{
			return true;
		}
	}

	if (board[0][0] == player && board[1][1] == player && board[2][2] == player|| board[0][2] == player && board[1][1] == player || board[2][0] == player)
	{
		return true;
	}

	return false;
}

bool FullBoard(const vector<vector<char>>& board)
{
	for (int d = 0; d < 3; d++)
	{
		for (int e = 0; e < 3; e++)
		{
			if (board[d][e] == ' ')
			{
				return false;
			}
		}
	}

	return true;
}

void PlayGame()
{
	vector<vector<char>> board(3, vector<char>(3, ' '));
	char crntPlayer = 'X';

	while (true)
	{
		DisplayBoard(board);

		int r, c;
		cout << "Player " << crntPlayer << "enter your move(row and colum): ";
		cin >> r >> c;

		if (r < 0 || r >= 3 || c < 0 || c >= 3 || board[r][c] != ' ')
		{
			cout << "Invalid Move Try Again." << endl;
			DisplayBoard(board);
		}

		board[r][c] = crntPlayer;

		if (Win(board, crntPlayer))
		{
			DisplayBoard(board);
			cout << "Congragulations! Player " << crntPlayer << "you have won." << endl;
		}

		if (FullBoard(board))
		{
			DisplayBoard(board);
			cout << "It's a tie." << endl;
		}

		crntPlayer = (crntPlayer == 'X') ? 'O' : 'X';

	}

}

int main()
{
	cout << "Welcome to tick toe game play." << endl;
	PlayGame();
	return 0;
}