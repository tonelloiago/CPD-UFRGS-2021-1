#include "header.h"

int recursions = 0;
int swaps = 0;

void swap(int array[], int i, int j)
{
    int varAux = array[i];
    array[i] = array[j];
    array[j] = varAux;
}

int partitionHoare(int array[], int initial, int final, int partitionID, int pivotID)
{

    int size = final - initial + 1;
    chooseThePivot(array, size, 0, initial, final);

    int pivot = array[initial];
    int i = initial - 1, j = final + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (array[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (array[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(array, i, j);
        swaps++;
    }
}

int partitionLomuto(int array[], int initial, int final, int partitionID, int pivotID)
{
    int size = final - initial + 1;
    chooseThePivot(array, size, partitionID, initial, final);

    int pivot = array[initial];
    int i = initial;

    for(int j = initial + 1; j <= final; j++) {
        
        if(array[j] <= pivot) {
            i++;
            swap(array, i, j);
            swaps++;
        }
    }

    swap(array, initial, i);
    swaps++;
    
    

    return i;
}



void quickSort(int array[], int size, int initial, int final, int partitionID, int pivotID)
{
    int pivotIndex;


    if(initial < final) {
        
        if(partitionID == 0)
            pivotIndex = partitionLomuto(array, initial, final, partitionID, pivotID);
        else
            pivotIndex = partitionHoare(array, initial, final, partitionID, pivotID);

        quickSort(array, size, initial, pivotIndex - 1, partitionID, pivotID);
        quickSort(array, size, pivotIndex + 1, final, partitionID, pivotID);
        recursions += 2;

    }

}

void quickSortA(int array[], int size, int initial, int final, int partitionID, int pivotID)
{
    quickSort(array, size, 0, size - 1, LOMUTO, MEDIAN);

    cout << recursions << "_" << swaps << endl;
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

extern int recursions;
extern int swaps;