#include "header.hpp"

int main(int argv, char **argc)
{
    system("exec rm -r saidas/*.txt");
    assert(argv == 2, "Usage ./main <file.txt>");

    cout << fixed;//Removes scientific notation
    read_and_sort(argc[1]);

    return 0;
}
