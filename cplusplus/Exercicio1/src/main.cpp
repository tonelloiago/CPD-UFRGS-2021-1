#include "header.hpp"

int main(int argv, char **argc)
{
    system("exec rm -r saidas/*.txt");
    assert(argv == 2, "Número de argumentos!");

    read_and_sort(argc[1]);

    return 0;
}
