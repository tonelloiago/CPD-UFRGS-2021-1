#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <iostream>


using namespace std;

int main() 
{
    char fName[50] = "war_and_peace_clean.txt";
    
    struct stat sb;
    long cntr = 0;
    int fd, lineLen;
    char *data;
    char *line;
    // map the file
    fd = open(fName, O_RDONLY);
    fstat(fd, &sb);

    data = static_cast<char*>(mmap((caddr_t)0, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0));
    

    return 0;


}