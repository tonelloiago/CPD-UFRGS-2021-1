#include "header.h"

int main()
{

    clock_t start_clock, end_clock;
    start_clock = clock();

    double duration = (end_clock - start_clock)/(double)CLOCKS_PER_SEC;

    int array[TAM_MAX];
    int auxiliaryArray[TAM_MAX];
    int size, i;
    string line;
    string delimiter = " ";

    ifstream inputFile("teste.txt");

    while(getline(inputFile, line)) {
        
        size_t pos;
        i = 0;
        /*Firsts find size of the array*/
        pos = line.find(delimiter);
        size = stoi(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());

        while((pos = line.find(delimiter)) != string::npos) {
            //Read array
            array[i] = stoi(line.substr(0, pos));
            auxiliaryArray[i] = stoi(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
            i++;
        }

        //Pega ultimo
        //array[i] = stoi(line.substr(0, pos));

        quickSortA(array, size, 0, size - 1, LOMUTO, MEDIAN);
        // update_array(array, auxiliaryArray, size);
        
        // quickSort(array, size, 0, size - 1, LOMUTO, RANDOM);
        // update_array(array, auxiliaryArray, size);
        
        // quickSort(array, size, 0, size - 1, HOARE, MEDIAN);
        // update_array(array, auxiliaryArray, size);
        
        // quickSort(array, size, 0, size - 1, HOARE, RANDOM);
        // update_array(array, auxiliaryArray, size);
        
    }




    

    return 0;

}