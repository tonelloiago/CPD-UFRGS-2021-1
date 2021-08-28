#include "header.hpp"

void assert(int flag, string message)
{
    if (flag == 0)
        cout << message << endl;
}

void sorting(string file_path)
{
    int size = 0;
    int count = 0;
    vector<int> gaps;
    string delimiter = " ";
    string line;
    ifstream file(file_path);
    ofstream out_file;
    bool flag_first_element = true;

    assert(file.is_open(), "Failed to open input file.");

    while (getline(file, line))
    {

        int array[INT16_MAX];
        int array_aux[INT16_MAX];
        size_t pos;
        int i = 0;

        //Read line and get size/array
        while ((pos = line.find(delimiter)) != string::npos)
        {
            if (flag_first_element)
            {
                //Read size
                size = stoi(line.substr(0, pos));
                cout << size << endl;
                line.erase(0, pos + delimiter.length());
                flag_first_element = false;
            }
            else
            {
                //Read array
                array[i] = stoi(line.substr(0, pos));
                array_aux[i] = stoi(line.substr(0, pos));
                line.erase(0, pos + delimiter.length());
                i++;
            }
        }

        //Orders each vector with shell sequence
        gaps = calculate_sequence(SHELL, size, gaps);
        shell_sort(array, size, gaps, SHELL, out_file);

        update_array(array, array_aux, size);

        //Orders each vector with knuth sequence
        gaps = calculate_sequence(KNUTH, size, gaps);
        shell_sort(array, size, gaps, KNUTH, out_file);

        update_array(array, array_aux, size);

        //Orders each vector with ciura sequence
        gaps = calculate_sequence(CIURA, size, gaps);
        shell_sort(array, size, gaps, CIURA, out_file);

        count++;
        flag_first_element = true;
    }
    out_file.close();
}

//back to original array
void update_array(int array[], int array_aux[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = array_aux[i];
    }
}

//(end_clock - start_clock)/(double)CLOCKS_PER_SEC