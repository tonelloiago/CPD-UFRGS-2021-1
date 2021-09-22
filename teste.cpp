#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define TAM_MAX 1000001

#define MEDIAN 0
#define RANDOM 1
#define LOMUTO 0
#define HOARE  1


using namespace std;

int calculateRandomPivot(int arraySize)
{
    unsigned seed = time(0);
    srand(seed);

    return rand() % arraySize;
}


int main()
{
    while(true)
        cout << calculateRandomPivot(5) << endl;
    return 0;
}
