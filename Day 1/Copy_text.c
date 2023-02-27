#include <stdio.h>

int main (int argc, char *argv[])
{
    //Your code goes here
    FILE *F_Satu, *F_Dua;
    char huruf;

    if (argc != 3) return 1;

    F_Satu = fopen(argv[1], "r");
    F_Dua = fopen(argv[2], "w");

    while (!feof(F_Satu))
    {
        huruf = fgetc(F_Satu);
        fputc(huruf, F_Dua);
    }
    fclose(F_Satu);
    fclose(F_Dua);
    return 0;
}