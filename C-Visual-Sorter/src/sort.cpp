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

	graphArray = new int[graphSize];

	srand(time(0));

	for (int i = 0; i < graphSize; i++)
	{
		//Random number generator between 10 and 100
		graphArray[i] = rand() % (100 - 10 + 1) + 10;
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

void Graph::render()
{
	cout << "update frame" << endl;

	glClear(GL_COLOR_BUFFER_BIT);

	//Loops through and prints out every item in array
	for (int i = 0; i < graphSize; i++)
	{
		glBegin(GL_POLYGON);

		//Getting correct position for vertices using left riemann sum formula (Calculus 1 was actually useful, wow!)
		float deltaX = (float) (2 / (float) graphSize);
		float starX = (float) (deltaX * i - 1);

		//Converts number from 0 to 100 to a number from -1 to 1
		float height = (float) ((float) (graphArray[i] * 2) / 100) - 1;

		//Newer OpenGL vertex buffer to be implemented
		/*
		//Vertex buffer
		float positions[8] =
		{
			//Bottom left vertex position
			starX, -1.0f,

			//Bottom right
			starX + deltaX, -1.0f,

			//Top right
			starX + deltaX, height,

			//Top left
			starX, height
		};*/

		// bottom left
		glColor4f(1, 0, 0, 0);
		glVertex2f(starX, -1);

		// bottom right
		glColor4f(0, 1, 0, 0);
		glVertex2f(starX + deltaX, -1);

		// top right
		glColor4f(0, 0, 1, 0);
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
}
