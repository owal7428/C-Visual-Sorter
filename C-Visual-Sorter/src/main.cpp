#include <iostream>

#include "sort.h"

using namespace std;

int main()
{
    int size, choice, numCompares, numSwaps;

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

    cout << endl;
    cout << "----Algorithms----" << endl;
    cout << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << endl;
    cout << "Choose an algorithm: ";

    cin >> choice;

    if (cin.fail() || choice > 3 || choice < 1)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input." << endl;
        return 0;
    }

    //Implement OpenGl

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 800, "C++ Visual Sorter", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    Graph newGraph(size, window);

    cout << "Window Created." << endl;
    /*
    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //glewInit();
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //Render here
        glClear(GL_COLOR_BUFFER_BIT);

        newGraph.render();

        if (choice == 1)
        {
            newGraph.bubbleSort();
        }
        else if (choice == 2)
        {
            newGraph.insertionSort();
        }
        else
        {
            newGraph.quickSort(0, size - 1);
        }

        //Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();

        break;
    }

    cout << "Finished." << endl;

    newGraph.delay(200);
    
    glfwTerminate();

	return 0;
}
