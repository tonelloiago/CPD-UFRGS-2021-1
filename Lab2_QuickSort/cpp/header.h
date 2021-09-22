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

void insertionSort(int *vet, int tam);
int findMedianIndex(int array[], int firstIndex, int meanIndex, int lastIndex, int median);
int calculateMedianOfThree(int first, int mean, int last);
int calculateMean(int first, int last);
int calculateRandomPivot(int arraySize);
void check_correctness (int C[], int tam);
void update_array(int array[], int auxiliaryArray[], int size);

void randomPartition(int array[], int initial, int final);
void swap(int array[], int i, int j);
int partitionLomuto(int array[], int initial, int final, int partitionID, int pivotID, int *swaps);
int partitionHoare(int array[], int initial, int final, int partitionID, int pivotID, int *swaps); 
void quickSort(int array[], int size, int initial, int final, int partitionID, int pivotID);
void chooseThePivot(int array[], int size, int pivotID, int first, int last);

void quickSortA(int array[], int size, int initial, int final, int partitionID, int pivotID);