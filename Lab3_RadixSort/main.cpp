#include "header.h"

RadixSort::RadixSort(string fileName)
{


    strcpy(this->fName, fileName.c_str());
    cout << fName << endl;

}
// }

void RadixSort::readInputFile()
{ 
    struct stat sb;
    long cntr = 0;
    int fd, lineLen;
    char *line;
    // map the file
    fd = open(this->fName, O_RDONLY);
    fstat(fd, &sb);

    data = static_cast<char*>(mmap((caddr_t)0, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0));

    
}

// void RadixSort::printArr()
// {
//     for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
//         printf("    %s\n", data[i].c_str());
//     }
// }



int main(void) {

    
    RadixSort teste = RadixSort("war_and_peace_clean.txt");
    puts("TESTE");

    teste.readInputFile();
    cout << teste.data << endl;

    puts("before sorting:");
    //teste.printArr();
    //radixSort(teste.data, (int)(sizeof(teste.data) / sizeof(teste.data[0])));
    puts("after sorting:");
    //teste.printArr();

    return 0;
}
