#include <iostream>
#include <cstdio>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <cstring>


using namespace std;


size_t getMax(string arr[], int n);
void countSort(string a[], int size, size_t k);
void radixSort(string b[], int r);


class RadixSort
{


    
public:

    char fName[50];
    //string data[15];
    char* data;

    
    RadixSort(string fileName);
    
    void readInputFile();
    void printArr();
};
