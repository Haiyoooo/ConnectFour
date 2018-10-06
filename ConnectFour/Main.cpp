using namespace std; //use standard namespace

#include <iostream> //without this, cout is undefined

//FUNCTIONS
void PrintGrid();
int CheckWin();

//VARIABLES
const int rows = 2; //6
const int col = 3; //7
char grid[rows][col] = { };



int main()
{
	cout << "Welcome to Connect Four\n";

		//Create the initial Grid
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < col; y++)
			{
				grid[x][y] = '.';

			}
		}
		PrintGrid();

		int player = 1;

		while (CheckWin() == 0)
		{
			// ask player to choose a column
			player = (player % 2 == 1 ? 1 : 2);
			if (player == 1)
			{
				cout << "Player X's turn! Choose a column (1-7): ";
			}
			else
			{
				cout << "Player O's turn! Choose a column (1-7): ";
			}
			int i = 0;
			cin >> i;

			// drop an X or O into the column chosen...
			if (i >= 1 && i <= col)
			{
				int r = rows - 1;

				while (grid[r][i - 1] != '.' && r >=0)
				{
					--r;
				}

				if (player == 1)
				{
					grid[r][i - 1] = 'X';
				}
				
				if (player == 2)
				{ 
					grid[r][i - 1] = 'O';
				}
				
				PrintGrid();
	
					
			}

			// if the player didn't enter a valid column number...
			else
			{
				cout << "boo \n";
			}

			player++;

		}

	system("pause");
	return 0;
}


//_________________PRINT GRID________________
void PrintGrid()
{
	cout << "1234567" << endl;
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < col; y++)
		{
			cout << grid [x][y];

		}
		cout << endl;
	}
}


int CheckWin() // 0 = game ongoing, 1 = game ended (win/draw)
{
		int filled = 0;
		// Check for four in a row starting with piece in the bottom left corner
	    /*  
			Direction of checks: to the right, then up a row
			5 ------> 6
			3 ------> 4
			1 ------> 2
		*/
		for (int j = 0; j < col; j++)
		{
			for (int i = rows - 1; i >= 0; i--)
			{
				//verticle win
				if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j] && grid[i][j] == grid[i - 3][j] && grid[i][j] == 'X')
				{
					cout << "Player X wins!" << endl;
					return 1;
				}

				else if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i - 2][j] && grid[i][j] == grid[i - 3][j] && grid[i][j] == 'O')
				{
					cout << "Player O wins!" << endl;
					return 1;
				}

				//horizontal win
				else if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3] && grid[i][j] == 'X')
				{
					cout << "Player X wins!" << endl;
					return 1;
				}

				else if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3] && grid[i][j] == 'O')
				{
					cout << "Player O wins!" << endl;
					return 1;
				}

				//diagonal win .-'
				else if (grid[i][j] == grid[i - 1][j + 1] && grid[i][j] == grid[i - 2][j + 2] && grid[i][j] == grid[i - 3][j + 3] && grid[i][j] == 'X')
				{
					cout << "Player X wins!" << endl;
					return 1;
				}

				else if (grid[i][j] == grid[i - 1][j + 1] && grid[i][j] == grid[i - 2][j + 2] && grid[i][j] == grid[i - 3][j + 3] && grid[i][j] == 'O')
				{
					cout << "Player O wins!" << endl;
					return 1;
				}

				//diagonal win '-.
				else if (grid[i][j] == grid[i - 1][j - 1] && grid[i][j] == grid[i - 2][j - 2] && grid[i][j] == grid[i - 3][j - 3] && grid[i][j] == 'X')
				{
					cout << "Player X wins!" << endl;
					return 1;
				}

				else if (grid[i][j] == grid[i - 1][j - 1] && grid[i][j] == grid[i - 2][j - 2] && grid[i][j] == grid[i - 3][j - 3] && grid[i][j] == 'O')
				{
					cout << "Player O wins!" << endl;
					return 1;
				}

				// check for draw
				// minus "filled" variable
				if (grid[i][j] != '.')
				{
					filled++;
				}

				if (filled == sizeof(grid))
				{
					cout << "Draw" << endl;
					return 1;
				}
				
			}
		}
	
	 return 0; 
	
			
	

}

