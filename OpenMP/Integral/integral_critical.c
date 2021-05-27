#include <stdio.h>
#include <omp.h>

#define NUMOFSTEPS 100000
#define NUMOFTHREADS 4

int main()
{
    int nthreads, i;
    double result;
    
    double step = 1.0/(double)NUMOFSTEPS;
    
    omp_set_num_threads(NUMOFTHREADS); // request 2 threads
    #pragma omp parallel
    {
        int i, id, nthrds;
        double x, sum;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        if(id == 0) // check how many threads you actually get
            nthreads = nthrds;

        for(i=id, sum=0.0; i<NUMOFSTEPS; i+=nthrds)
        {
            x = (i+0.5) * step;
            sum += 4.0/(1.0+x*x);
        }
        #pragma omp critical // ensures that only one htread can access at a time
            result += sum * step;
    }

    printf("The final result is %f\n", result);
    return 0;
}