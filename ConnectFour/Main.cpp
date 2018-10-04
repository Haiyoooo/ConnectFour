using namespace std; //use standard namespace

#include <iostream> //without this, cout is undefined

void PrintGrid();

//VARIABLES
const int rows = 6, col = 7;
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

		while (rows > 0)
		{
			PrintGrid();

			// ask player X to choose a column
			cout << "Player X's turn! Choose a column (1-7): ";
			int i = 0;
			cin >> i;

			// drop an X into the column chosen...
			if (i >= 1 && i <= col)
			{
				int r = rows - 1;

				while (grid[r][i - 1] != '.' && r >=0)
				{
					--r;
				}

				grid[r][i - 1] = 'X';
			}

			// if the player didn't enter a valid column number...
			else
			{
				cout << "boo \n";
			}


			PrintGrid();

			// ask player O to choose a column
			cout << "Player Y's turn! Choose a column (1-7): ";
			int j = 0;
			cin >> j;

			// drop an O into the column chosen...
			if (j >= 1 && j <= col)
			{
				int rr = rows - 1;

				while (grid[rr][j - 1] != '.' && rr >= 0)
				{
					--rr;
				}

				grid[rr][j - 1] = 'O';
			}

			// if the player didn't enter a valid column number...
			else
			{
				cout << "boo \n";
			}

		}

	system("pause");
	return 0;
}


//_________________PRINT A GRID________________
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

