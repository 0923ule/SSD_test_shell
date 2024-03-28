#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NAND "./nand.txt"
#define RESULT "./result.txt"

int main(int argc, char* argv[]) {
    uint32_t memory[100] = { 0, };

    char program[10];
    char RW;
    int number;
    uint32_t data;

    strcpy(program, argv[1]);
    RW = *argv[2];
    number = atoi(argv[3]);
    if (argv[4] != NULL)
        data = (uint32_t)strtoul(argv[4], NULL, 16);
    else data = 0;

    if (RW == 'W') {

        // ------------NAND file open------------ //
        FILE* file = fopen(NAND, "r+");
        if (file == NULL) {
            FILE* file = fopen(NAND, "w+");
        }
        file = fopen(NAND, "r+");

        // ------------read------------ //
        int tempNum;
        uint32_t tempData;

        while (fscanf(file, "%d : 0x%X\n", &tempNum, &tempData) == 2) {
            memory[tempNum] = tempData;
        }

        // ------------write------------ //
        memory[number] = data;

        // ------------save------------ //
        fseek(file, 0, SEEK_SET);
        for (int i = 0; i < 100; i++) {
            fprintf(file, "%d : 0x%X\n", i, memory[i]);
        }
        fclose(file);
    }
    else if (RW == 'R') {

        // ------------RESULT file open------------ //
        FILE* result_file = fopen(RESULT, "r+");
        if (result_file == NULL) {
            FILE* result_file = fopen(RESULT, "w+");
        }
        result_file = fopen(RESULT, "r+");

        // ------------NAND file open------------ //
        FILE* file = fopen(NAND, "r+");
        if (file == NULL) {
            FILE* result_file = fopen(NAND, "w+");
        }
        file = fopen(NAND, "r+");

        // ------------read------------ //
        int found = 0;
        int tempNum;
        uint32_t tempData;
        long int lastPos = 0;

        while (fscanf(file, "%d : 0x%X\n", &tempNum, &tempData) == 2) {
            if (tempNum == number) {
                found = 1;
                break;
            }
            lastPos = ftell(file);
        }

        // ------------save------------ //
        fseek(file, lastPos, SEEK_SET);
        if (found) fprintf(result_file, "0x%08X", tempData);
        else fprintf(result_file, "0x%08X", 0x00000000);
        fclose(result_file);
    }
    return 0;
}