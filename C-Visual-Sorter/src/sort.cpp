#include "sort.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Graph::Graph(int size)
{
	graphSize = size;

	graphArray = new int[graphSize];

	srand(time(0));

	for (int i = 0; i < graphSize; i++)
	{
		//Random number generator
		graphArray[i] = rand() % (100 - 10 + 1) + 10;
	}
}

Graph::~Graph()
{
	delete[] graphArray;
	graphArray = nullptr;
}

void Graph::swap(int first, int second)
{
	int temp = graphArray[first];
	graphArray[first] = graphArray[second];
	graphArray[second] = temp;
}

void Graph::printAll()
{
	for (int i = 0; i < graphSize; i++)
	{
		cout << graphArray[i] << " ";
	}
	cout << endl;
}

void Graph::bubbleSort()
{
	for (int i = 0; i < graphSize - 1; i++)
	{
		for (int j = 0; j < graphSize - 1 - i; j++)
		{
			if (graphArray[j] > graphArray[j + 1])
				swap(j, j + 1);
		}
	}
}
