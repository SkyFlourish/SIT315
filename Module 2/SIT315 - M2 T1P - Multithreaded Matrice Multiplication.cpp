//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <pthread.h>
#include <thread>
using namespace std;

// Initialize values.
#define MAX  100
int N;
int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];
int step_i = 0;

// Determine Max Threads, #define would probably work better, but the amount of threads may change and locking in a solution that is too high for one machine over the other can overwork a system.
const unsigned int MAX_THREADS = std::thread::hardware_concurrency();

//Function to preform Matrix Multiplication
void* multi(void* arg)
{
	int core = step_i++;

	//Each thread computes 1/ N of matrix multiplication
	for (int i = core * N/N; i < (core +1) * N/N ; i++)
		{ for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

}


int main()
{

	cout << "Please Enter the value of the square Matrices " << endl;

	cin >> N;

	//Randomly Generating Numbers for the Matrices
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = rand() % 15;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			B[i][j] = rand() % 15;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;
		}
	}

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; i < N; i++)
		{
			for (int k = 0; i < N; i++)
			{
				C[i][j] += A[i][j] * B[k][j];
			}
		}

	} */

	//Doing the Multiplication
	clock_t ProcessTime;
	ProcessTime = clock();

	//declaring maximum threads
	pthread_t threads[MAX_THREADS];

	//creating threads, each evaluating its own part
	for (int i =0; i < MAX_THREADS; i++)
	{
		int* p;
		pthread_create(&threads[i], NULL, multi, (void*)(p));
	}

	//joining and waiting for threads to complete
	for (int i = 0; i < MAX_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}

	//determining time taken
	float elapsedTime = (float)ProcessTime / CLOCKS_PER_SEC;
	cout << "Elapsed Time for Process:" <<elapsedTime << " Seconds" << endl;


	//Saving To File
	ofstream myFile("Matrice Multiplication.txt");
	if (myFile.is_open())
	{

		myFile << "Elapsed Time for Process:" << elapsedTime << " Seconds";
		myFile.close();
	}
	else cout << "Unable to Open File";
	int x;
	cin >> x;

    cout << "Thanks for using me" << endl;
    return 0;
}
