#pragma once

class Graph
{
	public:
		//Constructor and Destructor
		Graph(int graphSize);
		~Graph();

		void swap(int first, int second);

		void printAll();

		//Sorting algorithms
		void bubbleSort();

	private:
		//Array used for sorting
		int *graphArray;

		int graphSize;
		
};
