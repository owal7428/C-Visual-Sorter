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

		//Visual component (OpenGL)
		void render();

		//Sorting algorithms
		void bubbleSort();

	private:
		//Array used for sorting
		int *graphArray;
		
		int graphSize;
		GLFWwindow* window;
};
