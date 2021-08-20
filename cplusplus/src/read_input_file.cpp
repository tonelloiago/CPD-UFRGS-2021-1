#include "header.hpp"


void assert(int flag, string message)
{
    if(flag == 0)
        cout << message << endl;
}

void process_control(string file_path)
{
    //Opening the file
    int size = 0;
    int count = 0;
    string delimiter = " ";
    string line;
    ifstream file(file_path);

    assert(file.is_open(), "Failed to open input file.");

    while(getline(file, line)) {

        //Lines 0,2,4,... sizes
        //Lines 1,3,5,... arrays

        if(count % 2 == 0){
            size = stoi(line);
            cout << size << endl;
            count++;       
            continue;
        }
        else{

            int array[size];    //Não sei se isso é legal
            int array_aux[size];
            size_t pos;
            int i = 0;          //Usar vector
            
            while((pos = line.find(delimiter)) != string::npos) {
                array[i] = stoi(line.substr(0, pos));
                array_aux[i] = stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());
                i++;
            }

            vector<int> gaps;

            ofstream out_file;

            gaps = calculate_sequence(SHELL, size, gaps);
            shell_sort(array, size, gaps, SHELL, out_file);

            update_array(array, array_aux, size);

            gaps = calculate_sequence(KNUTH, size, gaps);
            shell_sort(array, size, gaps, KNUTH, out_file);

            update_array(array, array_aux, size);

            gaps = calculate_sequence(CIURA, size, gaps);
            shell_sort(array, size, gaps, CIURA, out_file);
            

            count++;
        }
    }
}

void update_array(int array[], int array_aux[], int size)
{
    for(int i = 0; i < size; i++){
        array[i] = array_aux[i];
    }
}


//(end_clock - start_clock)/(double)CLOCKS_PER_SEC