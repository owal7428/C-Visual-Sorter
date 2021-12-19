#pragma once

#include <chrono>
#include <thread>

//#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Graph
{
	public:
		//Constructor and Destructor
		Graph(int graphSize, GLFWwindow* windowPass);
		~Graph();

		//Back-end functions
		void swap(int first, int second);
		void printAll();
		void delay(int time);
		void resetArray();

		//Visual component (OpenGL)
		void render();

		//Sorting algorithms
		void bubbleSort();
		void insertionSort();
		void quickSort(int low, int high);

		int numCompares;
		int numSwaps;

	private:
		//Array used for sorting
		int *graphArray;
		int* graphArray_messy;

		int graphSize;
		GLFWwindow* window;

		//Helper for quicksort
		int partition(int low, int high);
};
