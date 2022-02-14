/* This program deals with arrays. It declares an array of 10 integers and fill
 * this array with values at compile-time. It then shifts the values in the array
 * to the right (circularly) by a user specified amount. Finally it prints
 * the array before and after the shifting.*/

#include <iostream>
using namespace std;

const int SIZE = 10; // the size of the array

int getUserTimes()
{
	int val;
	cout << "Please enter how many elements to shift the array: ";
	cin >> val;

	while (cin.fail())
	{
		cout << "#ERROR - Only integer  values are allowed!\n";
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please enter how many elements to shift the array: ";
		cin >> val;
	}
	return val;
}

/* Print the passed array on the screen
 * @return : void*/
void printArray(int myarray[])
{
	cout << "Array: [";
	for (int i = 0; i < SIZE; i++)
	{
		cout << myarray[i];
		if (i != SIZE - 1)
		{
			cout << ", ";
		}
	}
	cout << "]\n";
}

void shiftOne(int myarray[])
{
	// shifts the array with one value to the right
	int temp = myarray[SIZE - 1];
	for (int i = SIZE - 2; i >= 0; i--)
		myarray[i + 1] = myarray[i];
	myarray[0] = temp;
}

void shiftArray(int myarray[], int times)
{
	// Shifts the array times times to the right.

	int temp;
	for (int j = 1; j <= times; j++)
	{
		temp = myarray[SIZE - 1];
		for (int i = SIZE - 2; i >= 0; i--)
			myarray[i + 1] = myarray[i];
		myarray[0] = temp;
	}
}

/* This function asks the user to select the char "y" or "n"
 * @return : y for yes
 *           n for no
 */
char doAgain()
{ // defining local scope variables
	char value;

	cout << "\nDo you want to run the program again (y/n) ?:  ";
	cin >> value;
	while (cin.fail() || !(value == 'y' || value == 'n'))
	{
		cout << "#Error - only (y/n) are accepted!\n";
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Do you want to run the program again (y/n) ? :  ";
		cin >> value;
	}
	cout << endl;
	return value;
}

int main()
{
	// definitions
	int ThisArray[10] = {3, 17, 2, 9, 12, 8, 43, 100, 55, 6}; // array
	int x;													  // Numebr of times the array to be shifted

	// run the program as many times as the user wants
	do
	{
		// print the array (unmodified)
		cout << "Original array..\n";
		printArray(ThisArray);

		// Shift array once
		cout << "\n\nShifting array once..\n";
		shiftOne(ThisArray);

		// Print the array after shifting..
		cout << "\n\nPrint the array after shifting..\n";
		printArray(ThisArray);

		// Shifting the array many times
		x = getUserTimes();

		// shift the elements
		cout << "Shifting the array " << x << " times\n";
		shiftArray(ThisArray, x);

		// print the array (modified)
		cout << "print the array after " << x << " shifts";
		printArray(ThisArray);

	} while (doAgain() == 'y');

	return 0;
}
