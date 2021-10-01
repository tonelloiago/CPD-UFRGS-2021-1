#include "header.h"

UnsortedArray::UnsortedArray()
{
    
    int i;
    string line;
    string delimiter = " ";

    ifstream inputFile("entrada-quicksort.txt");

    while(getline(inputFile, line)) {


        this->recursions = 0;
        this->swaps = 0;
        size_t pos;
        i = 0;
        /*Firsts find size of the array*/
        pos = line.find(delimiter);
        this->size = stoi(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());

        while((pos = line.find(delimiter)) != string::npos) {
            //Read array
            this->array[i] = stoi(line.substr(0, pos));
            this->auxiliaryArray[i] = stoi(line.substr(0, pos));
            line.erase(0, pos + delimiter.length());
            i++;
        }

        for(int partition = LOMUTO; partition <= HOARE; partition++) {
            for(int pivot = MEDIAN; pivot <= RANDOM; pivot++) {
                calculateAndCheckResults(partition, pivot);
                check_correctness(array, size);
                update_array(array, auxiliaryArray, size);
            }
        }
    }
}

void UnsortedArray::calculateAndCheckResults(int partitionID, int pivotID)
{
        string statsFileName;

        start_clock = clock();
        /*call quicksort for the first time*/
        quickSort(0, size - 1, partitionID, pivotID);
        end_clock = clock();
        duration = (end_clock - start_clock)/double(CLOCKS_PER_SEC);

        /*choose the file name*/
        if(partitionID == LOMUTO) {
            if(pivotID == MEDIAN) {
                statsFileName = "stats-mediana-lomuto.txt";
            }
            else {
                statsFileName = "stats-aleatorio-lomuto.txt";
            }
        }
        else {
            if(pivotID == MEDIAN) {
                statsFileName = "stats-mediana-hoare.txt";
            }
            else {
                statsFileName = "stats-aleatorio-hoare.txt";
            }
        }
        writeOutput(statsFileName, pivotID, partitionID);
}

void UnsortedArray::writeOutput(string outputFileName, int pivotID, int partitionID)
{
    ofstream outputFile;
    outputFile << fixed;
    cout << fixed;
    outputFile.open("saidas/" + outputFileName, fstream::app);

    outputFile << "TAMANHO ENTRADA " << size << endl;
    outputFile << "SWAPS " << swaps << endl;
    outputFile << "RECURSOES " << recursions << endl;
    outputFile << "TEMPO " << duration <<" EM SEGUNDOS" << endl;

    string pivotName;
    string partitionName;

    if(partitionID == 0) {
        partitionName = "LOMUTO";
    }
    else {
        partitionName = "HOARE";
    }

    if(pivotID == 0) {
        pivotName = "MEDIAN OF THREE";
    }
    else {
        pivotName = "RANDOM";
    }

    cout << "/-------------/" << partitionName << " & "<< pivotName <<"/-------------/" << endl;
    cout << "TAMANHO ENTRADA " << size << endl;
    cout << "SWAPS " << swaps << endl;
    cout << "RECURSOES " << recursions << endl;
    cout << "TEMPO " << duration <<" EM SEGUNDOS" << endl;
    cout << endl;

    outputFile.close();

}

/*                      QuickSort Functions                     */

int UnsortedArray::partitionHoare(int initial, int final, int partitionID, int pivotID)
{
    int sizeAux = final - initial + 1;
    chooseThePivot(array, sizeAux, pivotID, initial, final);
    this->swaps++;

    int pivot = array[initial];
    int i = initial - 1, j = final + 1;
 
    while (true) {
        do {
            i++;
        } while (array[i] < pivot);
 
        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j) {
            return j;
        }
 
        swap(array, i, j);
        this->swaps++;
        
    }
}

int UnsortedArray::partitionLomuto(int initial, int final, int partitionID, int pivotID)
{
    int sizeAux = final - initial + 1;
    chooseThePivot(array, sizeAux, pivotID, initial, final);
    this->swaps++;

    int pivot = array[initial];
    int i = initial;

    for(int j = initial + 1; j <= final; j++) {
        
        if(array[j] <= pivot) {
            i++;
            swap(array, i, j);
            this->swaps++;
        }
    }

    swap(array, initial, i);
    this->swaps++;
    
    
    return i;
}


void UnsortedArray::quickSort(int initial, int final, int partitionID, int pivotID)
{
    int pivotIndex;

    if(initial < final) {
        
        if(partitionID == 0){
            pivotIndex = partitionLomuto(initial, final, partitionID, pivotID);
            quickSort(initial, pivotIndex - 1, partitionID, pivotID);
           quickSort(pivotIndex + 1, final, partitionID, pivotID);
        }
        else{
            pivotIndex = partitionHoare(initial, final, partitionID, pivotID);

            quickSort(initial, pivotIndex, partitionID, pivotID);
            quickSort(pivotIndex + 1, final, partitionID, pivotID);
        }
        recursions += 2;

    }
}
