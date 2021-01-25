#include <cmath>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <omp.h>
using namespace std;

int main()
{
    //Number of execution threads used in this program
    int N=4;
    omp_set_num_threads(N);
    #pragma omp parallel
    //specifies that a section of code should be executed by single thread (not necessarily the master thread)
    #pragma omp single
    printf("Number of threads in the current parallel region is %d\n",omp_get_num_threads());
    
    //Spawns a group of threads where each will have 20/N iterations from the loop         
    #pragma omp parallel for num_threads(N)
    for(int n=0; n<20; ++n)
    {
    	printf("Iteration id: %d\n", n);
	//Doing some arbitrary math operations just to create a load for the CPU
	long int i=0;
	for(int n=0; n<1000000000; ++n)
	{
	    i=i*i/i*i;
	}	
    }
    printf("Done.\n");
}