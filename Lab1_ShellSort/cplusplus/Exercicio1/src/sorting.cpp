#include "header.hpp"
#include <algorithm>    //To use reverse function

void shell_sort(int array[], int size, vector<int> gaps, int sequence, ofstream &out_file)
{
    int i, j;
    int key = 0, inc = 0, temp = 0;
    string seq_string;

    switch (sequence)
    {
        case 0:
            seq_string = "SHELL";
            break;
        case 1:
            seq_string = "KNUTH";
            break;
        case 2:
            seq_string = "CIURA";
            break;
        default:
            break;
    }

    out_file.open("saidas/saida1.txt", fstream::app);
    assert(out_file.is_open(), "Failed to open input file.");

    for (int k = 0; k < size; k++) {
        cout << array[k] << " ";
        out_file << array[k] << " ";
    }

    out_file << "INC=" << seq_string << endl;
    cout << "INC=" << seq_string << endl;

    /*Shell Sort*/
    for (const auto &inc : gaps) {
         for (int i = inc; i < size;i ++) {

            key = array[i];
            j = i - inc;

            while(j >= 0 && key < array[j]) {
                array[j+inc] = array[j];
                j -= inc;
            }
            
            array[j+inc] = key;
        }

        for (int k = 0; k < size; k++) {
            cout << array[k] << " ";
            out_file << array[k] << " ";
        }
        
        cout << "INC= " << inc << endl;
        out_file << "INC=" << inc << endl;//write_file

    }
    out_file.close();
}

//Calculates sequence used by shell sort
vector<int> calculate_sequence(int sequence, int array_size, vector<int> gaps)
{
    int h = array_size;
    int i = 0;
    gaps.clear(); //Clear vector of gaps

    switch (sequence)
    {
        case SHELL: //Calculate SHELL sequence
            
            while (h > 1) {
                gaps.push_back(h / 2); //Inserts the gap in descending order
                h /= 2;
                i++;
            }
            break;

        case KNUTH://Calculate KNUTH sequence

            h = 1;
            while (h < array_size / 3)
                h = h * 3 + 1;          //Find max gap for this vector

            gaps.push_back(h);

            while (h > 1) {
                h /= 3;
                gaps.push_back(h);
            }
            break;

        case CIURA: //Calculate CIURA sequence
            
            vector<int> ciura = {1, 4, 10, 23, 57, 132, 301, 701}; //Defined until 701

            i = 0;
            h = 701;
            int newGap = 0;     
            int nextGap = 0;//Auxiliar to control the loop

            while (nextGap < array_size) {
                if (newGap >= 701) {

                    h *= 2.25;
                    newGap = h;
                    gaps.push_back(newGap);
                    nextGap = h * 2.25;
                }
                else {

                    newGap = ciura.at(i);
                    gaps.push_back(newGap); 

                    if(ciura.at(i) < 701)
                        nextGap = ciura.at(i + 1);
                    else
                        nextGap = h * 2.25;
                }
                i++;
            }
            reverse(gaps.begin(), gaps.end());
            break;
        }

    return gaps;
}
