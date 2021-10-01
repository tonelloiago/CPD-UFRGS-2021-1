#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#define TAM_MAX 1000001

#define MEDIAN 0
#define RANDOM 1
#define LOMUTO 0
#define HOARE  1

using namespace std;

class UnsortedArray
{

public:

    int array[TAM_MAX];
    int auxiliaryArray[TAM_MAX];
    int size;
    clock_t start_clock, end_clock;

    /*Infos*/
    double duration;
    int recursions;
    int swaps;
    
    UnsortedArray();
    void calculateAndCheckResults(int partitionID, int pivotID);
    void writeOutput(string outputFileName, int pivotID, int partitionID);

    /*Quick Sort Algorithm*/
    void quickSort(int initial, int final, int partitionID, int pivotID);
    int partitionLomuto(int initial, int final, int partitionID, int pivotID);
    int partitionHoare(int initial, int final, int partitionID, int pivotID); 
    
};

/*Auxiliary functions*/
void insertionSort(int *vet, int tam);
int findMedianIndex(int array[], int firstIndex, int meanIndex, int lastIndex, int median);
int calculateMedianOfThree(int first, int mean, int last);
int calculateMean(int first, int last);
int calculateRandomPivot(int arraySize);
void check_correctness (int C[], int tam);
void update_array(int array[], int auxiliaryArray[], int size);

void swap(int array[], int i, int j);
void randomPartition(int array[], int initial, int final);
void chooseThePivot(int array[], int size, int pivotID, int first, int last);
