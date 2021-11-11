#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *infile = fopen(argv[1], "rb");
    unsigned long buffer[8];

    FILE *write_ptr = fopen("part1-output","wb");


    int pTable[] = {2, 4, 1, 7, 3, 5, 6}; 

    while(fread(buffer, sizeof(unsigned long), 1, infile) > 0){
        int pageNum = *buffer >> 7;
        unsigned long frameNum = pTable[pageNum];
        unsigned long offset = *buffer & 0x7f;
        unsigned long physicalAddress = frameNum << 7 | offset;

        fwrite(&physicalAddress, sizeof(unsigned long), 1, write_ptr);
    }

    fclose(infile);

    return 0;
}