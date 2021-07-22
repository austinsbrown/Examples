#include <stdio.h>
#include <omp.h>

struct Compare
{
    int val;
    int index;
}Compare;

#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

void selectionSort(int*, int n);
void swap(int*, int*);
void printArray(int*, int);

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int* arr, int size)
{
    for (int i = size - 1; i > 0; --i)
    {
        struct Compare max;
        max.val = arr[i];
        max.index = i;
        #pragma omp parallel for reduction(maximum:max) // user defiend reduction
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > max.val)
            {
                max.val = arr[j];
                max.index = j;
            }
        }
        int tmp = arr[i];
        arr[i] = max.val;
        arr[max.index] = tmp;
    }
}


void printArray(int* arr, int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
