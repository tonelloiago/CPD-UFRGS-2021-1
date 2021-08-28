#include "header.hpp"
#include <algorithm>
#include <cmath>

void shell_sort(int array[], int size, vector<int> gaps, int sequence, ofstream &out_file)
{
    int i, j;
    int key = 0, inc = 0, temp = 0;
    string seq;

    switch (sequence)
    {
    case 0:
        seq = "SHELL";
        break;
    case 1:
        seq = "KNUTH";
        break;
    case 2:
        seq = "CIURA";
        break;
    default:
        break;
    }

    out_file.open("saidas/saida1.txt", fstream::app);

    for (int k = 0; k < size; k++)
    {
        cout << array[k] << " ";
        out_file << array[k] << " ";
    }

    out_file << "INC=" << seq << endl;
    cout << "INC=" << seq << endl;

    /*Shell Sort*/
    for (const auto &inc : gaps)
    {

        for (int i = inc; i < size; i += 1)
        {

            temp = array[i];

            for (j = i; j >= inc && array[j - inc] > temp; j -= inc)
                array[j] = array[j - inc];

            array[j] = temp;
        }

        for (int k = 0; k < size; k++)
        {
            cout << array[k] << " ";
            out_file << array[k] << " ";
        }
        cout << "INC= " << inc << endl;
        out_file << "INC=" << inc << endl;

        //write_file
    }

    out_file.close();
}

//Calculates sequence used by shell sort
vector<int> calculate_sequence(int type_sequence, int array_size, vector<int> gaps)
{
    int h = array_size;
    int i = 0;
    gaps.clear(); //Clear vector of gaps

    switch (type_sequence)
    {
    case SHELL:
        //Calculate SHELL sequence
        while (h > 1)
        {
            gaps.push_back(h / 2); //Inserts the gap in descending order
            h /= 2;
            i++;
        }

        break;

    case KNUTH:
        //Calculate KNUTH sequence
        h = 1;
        while (h < array_size / 3)
            //Find max gap for this vector
            h = h * 3 + 1;

        gaps.push_back(h);

        while (h > 1)
        {
            h /= 3;
            gaps.push_back(h);
        }

        break;

    case CIURA:
        //Calculate CIURA sequence
        vector<int> ciura = {1, 4, 10, 23, 57, 132, 301, 701}; //Defined until 701

        i = 0;
        h = 701;
        while (ciura.at(i) < array_size)
        {

            if (ciura.at(i) > 701 || h > 701) //Inserts the gap in descending order
            {
                h *= 2.25;
                gaps.push_back(h);
            }
            else
                gaps.push_back(ciura.at(i)); //Inserts the gap in descending order
            i++;
        }

        reverse(gaps.begin(), gaps.end());

        break;
    }

    return gaps;
}
