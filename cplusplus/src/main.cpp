#include "header.hpp"

int main(int argv, char** argc)
{
    system("exec rm -r saidas/*.txt");
    assert(argv == 2, "Número de argumentos!");

    process_control(argc[1]);
    
    return 0;
}
 