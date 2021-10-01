#include "header.h"


void swap(int array[], int i, int j)
{
    int varAux = array[i];
    array[i] = array[j];
    array[j] = varAux;
}

void chooseThePivot(int array[], int size, int pivotID, int first, int last)
{
    int auxValue;
    switch (pivotID)
    {
        case 0://MEDIAN of 3

            int firstIndex;
            firstIndex = first;
            int lastIndex;
            lastIndex = last;

            int meanIndex;
            int median;
            int medianIndex;
            meanIndex = calculateMean(firstIndex, lastIndex);
            median = calculateMedianOfThree(array[firstIndex], array[meanIndex], array[lastIndex]);
            medianIndex = findMedianIndex(array, firstIndex, meanIndex, lastIndex, median);

            /*The pivot is placed in the first position*/
            auxValue = array[first];
            array[first] = array[medianIndex];
            array[medianIndex] = auxValue;
            break;
        
        case 1: //Random

            int randomPivotIndex;
            randomPivotIndex = calculateRandomPivot(size);

            auxValue = array[first];
            array[first] = array[first + randomPivotIndex];
            array[first + randomPivotIndex] = auxValue;
            break;
    }

}


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