#include <stdio.h>
#include <omp.h>

#define ARR_SIZE 8                                                  

void printArr(int[ARR_SIZE][ARR_SIZE]);                           

int main()                                     
{
    int arr1[ARR_SIZE][ARR_SIZE] =                                 
    {                                      
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8}                                      
    };                                     

    int arr2[ARR_SIZE][ARR_SIZE] =                               
    {                                      
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,8},                                     
        {1,2,3,4,5,6,7,9}                                      
    };                                     

    int result[ARR_SIZE][ARR_SIZE];                                
    int i, j, k;
    #pragma omp parallel shared(arr1,arr2,result) private(i,j,k)
    {
        #pragma omp for 
        for(i=0; i<ARR_SIZE; i++)                                   
        {                                      
            for(j=0; j<ARR_SIZE; j++)                             
            {                                      
                result[i][j] = 0;                                      
                for(k=0; k<ARR_SIZE; k++)                                                                     
                    result[i][j] += arr1[i][k] * arr2[k][j];                                              
            }                                      
        }  
    }                                    
    
    printArr(result);                                           

    return 0;                                      
}                                      

void printArr(int arr[ARR_SIZE][ARR_SIZE])                          
{
    for(int i=0; i<ARR_SIZE; i++)
    {
        for(int j=0; j<ARR_SIZE; j++)
        {
            printf("%d", arr[i][j]);
            if(i != ARR_SIZE-1 || j != ARR_SIZE-1)
                printf(", ");
        }
        printf("\n");
    }
    printf("\n");
}