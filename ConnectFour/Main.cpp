using namespace std; //use standard namespace

#include <iostream> //without this, cout is undefined

int main()
{
	cout << "Welcome to Connect Four\n";

	//creating the grid
	char grid[7][7] = { "." };
	cout << grid;
	cout << "\n";

	system("pause");
	return 0;
}