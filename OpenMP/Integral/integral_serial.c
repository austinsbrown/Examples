#include <stdio.h>

#define NUMOFSTEPS 100000

int main()
{   
    double step = 1.0/(double)NUMOFSTEPS;
    double x, result;
    double sum = 0.0;

    for(int i=0; i<NUMOFSTEPS; i++)
    {
        x = (i+0.5)*step;
        sum += 4/(1.0+x*x);
    }

    result = step*sum;

    printf("Result is %f\n", result);
    return 0;
}