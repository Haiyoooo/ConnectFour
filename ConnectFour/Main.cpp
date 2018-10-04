using namespace std; //use standard namespace

#include <iostream> //without this, cout is undefined

void PrintGrid();

//Variables
const int rows = 6, col = 7;
char grid[rows][col] = { };

int main()
{
	cout << "Welcome to Connect Four\n";

		//Create the initial Grid
		cout << "1234567" << endl;
		for (int x = 0; x < rows; x++)
		{
			for (int y = 0; y < col; y++)
			{
				grid[x][y] = '.';

			}
		}

		PrintGrid();

		// ask player to choose a colmun
		cout << "Choose a column (1-7):" << endl;
		int i = 0;
		cin >> i;

		// check if input is valid
		if (i >= 1 && i <= col) //VALID
		{
			cout << "yay \n";
			grid[rows-1][i-1] = 'X';
		}
		else //INVALID
		{
			cout << "boo \n";
		}

		PrintGrid();


	system("pause");
	return 0;
}


//_________________PRINT A GRID________________
void PrintGrid()
{
	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < col; y++)
		{
			cout << grid [x][y];

		}
		cout << endl;
	}
}

