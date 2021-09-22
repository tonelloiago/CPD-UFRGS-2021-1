#include "header.h"

void insertionSort(int *vet, int tam)
{
    int i, j, x;
    for (i = 1; i < tam; i++)
    {
        x = vet[i];
        j = i - 1;
        while (x < vet[j] && j >= 0)
        {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = x;
    }
}

int findMedianIndex(int array[], int firstIndex, int meanIndex, int lastIndex, int median)
{
    int found;
    if(array[firstIndex] == median)
        found = firstIndex;
    else
        if(array[meanIndex] == median)
            found = meanIndex;
        else 
            found = lastIndex;

    return found;
}

int calculateMedianOfThree(int first, int mean, int last)
{
    int findMedianArray[3] = {first, mean, last};


    insertionSort(findMedianArray, 3);

    return findMedianArray[1];
}

/*Find the mean of the two indices*/
int calculateMean(int first, int last)
{
    return (first + last) / 2;
}

/*Generates a new pivot for the array (or sub-array)*/
int calculateRandomPivot(int arraySize)
{
    unsigned seed = time(0);
    srand(seed);
    
    return rand() % arraySize;
}

void check_correctness (int C[], int tam)
{
    for (int i=0; i<tam-1; i++) {
        if (C[i]>C[i+1]) {
            printf ("\n***** INCORRECT ORDERING *****");
            return;
        }
    }
}

//back to original array
void update_array(int array[], int auxiliaryArray[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = auxiliaryArray[i];
}