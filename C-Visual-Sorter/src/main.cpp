#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int size, numCompares, numSwaps;

	cout << "Number of bars sorted (Between 10 and 500): ";
	cin >> size;

    //Checks if input is invalid
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input." << endl;
        return 0;
    }

    if (size < 10)
    {
        cout << "Input too small." << endl;
        return 0;
    }
    else if (size > 500)
    {
        cout << "Input too large." << endl;
        return 0;
    }

    Graph newGraph(size);

    numCompares = 0;
    numSwaps = 0;

    //Implement OpenGl

	return 0;
}