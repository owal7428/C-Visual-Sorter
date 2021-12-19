#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

using namespace std;

//Constructor
Graph::Graph(int size, GLFWwindow* windowPass)
{
	graphSize = size;
	window = windowPass;

	numCompares = 0;
	numSwaps = 0;

	completed = false;

	graphArray = new int[graphSize];

	srand(time(0));

	for (int i = 0; i < graphSize; i++)
	{
		//Random number generator between 10 and 100
		graphArray[i] = rand() % (100 - 10 + 1) + 10;
	}

	graphArray_messy = new int[graphSize];

	for (int i = 0; i < graphSize; i++)
	{
		graphArray_messy[i] = graphArray[i];
	}
}

//Destructor
Graph::~Graph()
{
	delete[] graphArray;
	graphArray = nullptr;
}

//Basic function used to swap
void Graph::swap(int first, int second)
{
	int temp = graphArray[first];
	graphArray[first] = graphArray[second];
	graphArray[second] = temp;

	render();

	//delay(1);
}

void Graph::printAll()
{
	for (int i = 0; i < graphSize; i++)
	{
		cout << graphArray[i] << " ";
	}
	cout << endl;
}

//Simple delay function
void Graph::delay(int time)
{
	using namespace std::this_thread;
	using namespace std::chrono;

	sleep_until(system_clock::now() + milliseconds(time * 10));
}

void Graph::resetArray()
{
	for (int i = 0; i < graphSize; i++)
	{
		graphArray[i] = graphArray_messy[i];
	}
}

void Graph::render()
{
	cout << "update frame" << endl;

	glClear(GL_COLOR_BUFFER_BIT);

	//Loops through and prints out every item in array
	for (int i = 0; i < graphSize; i++)
	{
		//Getting correct position for vertices using left riemann sum formula (Calculus 1 was actually useful, wow!)
		float deltaX = (float) (2 / (float) graphSize);
		float starX = (float) (deltaX * i - 1);

		//Converts number from 0 to 100 to a number from -1 to 1
		float height = (float) ((float) (graphArray[i] * 2) / 100) - 1;

		//Creates rectangle with fill color of white
		glBegin(GL_POLYGON);

		// bottom left
		glColor4f(1, 1, 1, 1);
		glVertex2f(starX, -1);

		// bottom right
		glColor4f(1, 1, 1, 1);
		glVertex2f(starX + deltaX, -1);

		// top right
		glColor4f(1, 1, 1, 1);
		glVertex2f(starX + deltaX, height);

		// top left
		glColor4f(1, 1, 1, 1);
		glVertex2f(starX, height);

		glEnd();

		//Creates black outline for rectangles
		glBegin(GL_LINE_LOOP);

		// bottom left
		glColor4f(0, 0, 0, 1);
		glVertex2f(starX, -1);

		// bottom right
		glColor4f(0, 0, 0, 1);
		glVertex2f(starX + deltaX, -1);

		// top right
		glColor4f(0, 0, 0, 1);
		glVertex2f(starX + deltaX, height);

		// top left
		glColor4f(0, 0, 0, 1);
		glVertex2f(starX, height);

		glEnd();
	}

	//Swap front and back buffers
	glfwSwapBuffers(window);

	//Poll for and process events
	glfwPollEvents();
}

//Sorting algorithms go here
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

	render();

	completed = true;
}

void Graph::insertionSort()
{
	int key, j;

	for (int i = 1; i < graphSize; i++)
	{
		key = graphArray[i];
		j = i - 1;

		while (j >= 0 && graphArray[j] > key)
		{
			graphArray[j + 1] = graphArray[j];
			j = j - 1;

			render();
		}

		graphArray[j + 1] = key;

		render();
	}

	completed = true;
}

void Graph::quickSort(int low, int high)
{
	if (low < high)
	{
		int pIndex = partition(low, high);

		quickSort(low, pIndex - 1);
		quickSort(pIndex + 1, high);
	}

	completed = true;
}

int Graph::partition(int low, int high)
{
	int pivot = graphArray[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (graphArray[j] < pivot)
		{
			i++;
			swap(i, j);
		}
	}

	swap(i + 1, high);

	return (i + 1);
}
