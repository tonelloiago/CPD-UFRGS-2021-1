#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

#define SHELL 0
#define KNUTH 1
#define CIURA 2

using namespace std;

void process_control(string file_path);
void assert(int flag, string message);
vector<int> calculate_sequence(int type_sequence, int array_size, vector<int> gaps);
void shell_sort(int array[], int size, vector<int> gaps, int sequence, ofstream &out_file);
void update_array(int array[], int array_aux[], int size);