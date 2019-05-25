#include <iostream>
#include <fstream>
#include <ctime>
#include <omp.h>
using namespace std;
const int MAX = 825;

int main()
{
	// Initialize values.
	int N;

	//unsigned int MAX = hardware_concurrency();
	cout << "Please Enter the value of the square Matrices " << endl;
	cin >> N;
	int A[MAX][MAX];
	int B[MAX][MAX];
	int C[MAX][MAX];
    int thread_number = omp_get_max_threads();


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

    //Initialise 0 value for Result Matrix
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			C[i][j] = 0;
		}
	}

 /*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				C[i][j] += A[i][j] * B[k][j];
			}
		}

	}  */

    //Doing the Multiplication
	clock_t ProcessTime;
	ProcessTime = clock();

    #pragma omp parrallel shared (A,B,C,N)
    {
        #pragma omp for
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

    }
    	float elapsedTime = (float)ProcessTime / CLOCKS_PER_SEC;
	    cout << "Elapsed Time for Process:" <<elapsedTime << "Seconds";


	//Saving To File
	ofstream myFile("Matrice Multiplication.txt");
	if (myFile.is_open())
	{

		myFile << "Elapsed Time for Process:" << elapsedTime << "Seconds";
		myFile.close();
	}
	else cout << "Unable to Open File";
	int x;
	cin >> x;


    return 0;
}
