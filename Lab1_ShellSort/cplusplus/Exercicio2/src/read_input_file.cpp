#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

#define SHELL 0
#define KNUTH 1
#define CIURA 2


using namespace std;

void assert(int flag, string message)
{
    if (flag == 0)
        cout << message << endl;
}

void read_and_sort(string file_path)
{
    int size = 0;
    vector<int> gaps;
    int array[1000001];
    int array_aux[1000001];
    string delimiter = " ";
    string line;
    ifstream file(file_path);
    ofstream out_file;
    bool flag_first_element = true;

    assert(file.is_open(), "Failed to open input file.");

    while (getline(file, line)) {

        size_t pos;
        int i = 0;

        //Read line and get size/array
        while ((pos = line.find(delimiter)) != string::npos) {
            if (flag_first_element) {
                //Read size
                size = stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());
                flag_first_element = false;
            }
            else {
                //Read array
                array[i] = stoi(line.substr(0, pos));
                array_aux[i] = stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());
                i++;
            }
        }

        for(int sequence = 0; sequence <= 2; sequence++) {

            gaps = calculate_sequence(sequence, size, gaps);        //Calculate gaps for each sequence
            shell_sort(array, size, gaps, sequence, out_file);      //Sorting with shell sort algorithm
            check_correctness(array, size);                         
            update_array(array, array_aux, size);                   //Updates original array

        }

        flag_first_element = true;
    }
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
void update_array(int array[], int array_aux[], int size)
{
    for (int i = 0; i < size; i++)
        array[i] = array_aux[i];
}

