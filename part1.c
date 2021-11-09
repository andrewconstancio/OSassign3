#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *infile = fopen(argv[1], "rb");
    unsigned long buffer[8];

    int pTable[] = {2, 4, 1, 7, 3, 5, 6}; 

    while(fread(buffer, sizeof(unsigned long), 1, infile) > 0){
        int pageNum = *buffer >> 7;
        unsigned long frameNum = pTable[pageNum];
        unsigned long offset = *buffer & 0x7f;
        unsigned long physicalAddress = frameNum << 7 | offset;

        printf("Virtual Address: 0x%lx -> Physical Address: 0x%lx\n", *buffer, physicalAddress);
    }

    fclose(infile);

    return 0;
}